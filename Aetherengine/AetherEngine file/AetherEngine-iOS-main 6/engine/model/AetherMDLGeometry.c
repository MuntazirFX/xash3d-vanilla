/* AetherMDLGeometry.c — GoldSrc MDL v10 geometry/material extraction.
 * AetherEngine-iOS · Clean-room.
 *
 * Studio vertices/normals are vec3_t (12 bytes). Bone indices are separate
 * byte arrays. Triangle command streams contain vertex, normal, s and t
 * shorts. This implementation expands strip/fan commands into a triangle list
 * while retaining UVs and source bone indices for the animation stage.
 */
#include "AetherMDLGeometry.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MDL_HEADER_SIZE          244u
#define MDL_MESH_SIZE             20u
#define MDL_MODEL_SIZE           112u
#define MDL_BODYPART_SIZE         76u
#define MDL_VERTEX_SIZE           12u
#define MDL_COMMAND_VERTEX_SIZE    8u
#define MDL_TEXTURE_SIZE          80u

#define OFF_NUMTEX               180u
#define OFF_TEXIDX               184u
#define OFF_TEXDATAIDX            188u
#define OFF_NUMSKINREF            192u
#define OFF_NUMSKINFAM            196u
#define OFF_SKINIDX               200u
#define OFF_NUMBODY               204u
#define OFF_BODYIDX               208u

static i32 rd_i32(const u8 *p) {
    return (i32)((u32)p[0] | ((u32)p[1]<<8) | ((u32)p[2]<<16) | ((u32)p[3]<<24));
}
static u16 rd_u16(const u8 *p) {
    return (u16)((u32)p[0] | ((u32)p[1]<<8));
}
static i16 rd_i16(const u8 *p) {
    return (i16)rd_u16(p);
}
static f32 rd_f32(const u8 *p) {
    u32 v = (u32)p[0] | ((u32)p[1]<<8) | ((u32)p[2]<<16) | ((u32)p[3]<<24);
    f32 f; memcpy(&f, &v, sizeof f); return f;
}
static bool range_ok(u32 offset, u64 bytes, u32 size) {
    return offset <= size && bytes <= (u64)(size - offset);
}

#pragma pack(push, 1)
typedef struct mdl_mesh_disk {
    i32 num_tris;
    i32 tri_indexes;
    i32 skin_ref;
    i32 num_norms;
    i32 norm_info_index;
} mdl_mesh_disk_t;

typedef struct mdl_model_disk {
    char name[64];
    i32 type;
    f32 bounding_radius;
    i32 num_meshes;
    i32 mesh_index;
    i32 num_verts;
    i32 vert_info_index;
    i32 vert_index;
    i32 num_norms;
    i32 norm_info_index;
    i32 norm_index;
    i32 num_groups;
    i32 group_index;
} mdl_model_disk_t;

typedef struct mdl_bodypart_disk {
    char name[64];
    i32 num_models;
    i32 base;
    i32 model_index;
} mdl_bodypart_disk_t;
#pragma pack(pop)

static u32 command_triangles(const u8 *raw, u32 raw_size, i32 command_offset) {
    if (!raw || command_offset <= 0 || !range_ok((u32)command_offset, 2, raw_size)) return 0;
    const u8 *p = raw + (u32)command_offset, *end = raw + raw_size;
    u64 produced = 0;
    for (u32 groups = 0; groups < 65535u && p + 2 <= end; ++groups) {
        i16 sc = rd_i16(p); p += 2;
        if (sc == 0) break;
        u32 n = (u32)(sc < 0 ? -sc : sc);
        u64 bytes = (u64)n * MDL_COMMAND_VERTEX_SIZE;
        if ((u64)(end - p) < bytes) break;
        if (n >= 3) produced += (u64)n - 2u;
        p += bytes;
    }
    return produced > 0xFFFFFFFFu ? 0 : (u32)produced;
}

static u32 total_triangles(const u8 *raw, u32 size, i32 body_count, i32 body_offset) {
    u64 total = 0;
    for (i32 bp=0; bp<body_count; ++bp) {
        u32 bo=(u32)body_offset+(u32)bp*MDL_BODYPART_SIZE;
        if(!range_ok(bo,MDL_BODYPART_SIZE,size)) break;
        const mdl_bodypart_disk_t *b=(const mdl_bodypart_disk_t*)(raw+bo);
        if(b->num_models<=0||b->model_index<=0) continue;
        for(i32 mi=0;mi<b->num_models;++mi) {
            u32 mo=(u32)b->model_index+(u32)mi*MDL_MODEL_SIZE;
            if(!range_ok(mo,MDL_MODEL_SIZE,size)) break;
            const mdl_model_disk_t *m=(const mdl_model_disk_t*)(raw+mo);
            if(m->num_meshes<=0||m->mesh_index<=0) continue;
            for(i32 j=0;j<m->num_meshes;++j) {
                u32 xo=(u32)m->mesh_index+(u32)j*MDL_MESH_SIZE;
                if(!range_ok(xo,MDL_MESH_SIZE,size)) break;
                const mdl_mesh_disk_t *x=(const mdl_mesh_disk_t*)(raw+xo);
                if(x->num_tris>0) total += command_triangles(raw,size,x->tri_indexes);
            }
        }
    }
    return total > 0xFFFFFFFFu ? 0 : (u32)total;
}

static void make_default_texture(aether_model_mesh_t *out) {
    out->texture_width=1; out->texture_height=1;
    out->texture_rgba=(u8*)malloc(4);
    if(out->texture_rgba){ out->texture_rgba[0]=190;out->texture_rgba[1]=190;out->texture_rgba[2]=190;out->texture_rgba[3]=255; }
}

/* Decode the first embedded studio texture. The palette follows its indexed
   pixel data: width*height bytes followed by 256 RGB triples. */
static void extract_first_texture(const aether_mdl_t *mdl, aether_model_mesh_t *out) {
    u32 size=0; const u8 *raw=aether_mdl_raw_data(mdl,&size);
    if(!raw || size<MDL_HEADER_SIZE){make_default_texture(out);return;}
    i32 ntex=rd_i32(raw+OFF_NUMTEX), texoff=rd_i32(raw+OFF_TEXIDX);
    i32 dataoff=rd_i32(raw+OFF_TEXDATAIDX);
    if(ntex<=0||texoff<=0||dataoff<=0){make_default_texture(out);return;}
    if(!range_ok((u32)texoff,(u64)ntex*MDL_TEXTURE_SIZE,size)){make_default_texture(out);return;}
    const u8 *t=raw+(u32)texoff;
    i32 w=rd_i32(t+68), h=rd_i32(t+72), pixoff=rd_i32(t+76);
    if(w<=0||h<=0||w>4096||h>4096||pixoff<=0){make_default_texture(out);return;}
    u64 pixels=(u64)w*(u64)h, palette=256u*3u;
    if(!range_ok((u32)(dataoff+pixoff),pixels+palette,size)){make_default_texture(out);return;}
    const u8 *pix=raw+(u32)(dataoff+pixoff);
    const u8 *pal=pix+pixels;
    out->texture_rgba=(u8*)malloc((size_t)pixels*4u);
    if(!out->texture_rgba){out->texture_width=out->texture_height=0;return;}
    out->texture_width=(u32)w;out->texture_height=(u32)h;
    for(u64 i=0;i<pixels;++i){
        u32 c=(u32)pix[i];
        out->texture_rgba[i*4+0]=pal[c*3+0];
        out->texture_rgba[i*4+1]=pal[c*3+1];
        out->texture_rgba[i*4+2]=pal[c*3+2];
        out->texture_rgba[i*4+3]=(c==255u)?0:255; /* GoldSrc transparency index. */
    }
}

aether_result_t aether_mdl_geometry_extract(const aether_mdl_t *mdl,
                                             aether_model_mesh_t **out_mesh) {
    if(!mdl||!out_mesh||!aether_mdl_is_valid(mdl)) return AETHER_ERR_INVALID_ARG;
    *out_mesh=NULL;
    u32 size=0; const u8 *raw=aether_mdl_raw_data(mdl,&size);
    if(!raw||size<MDL_HEADER_SIZE) return AETHER_ERR_INVALID_ARG;

    i32 body_count=rd_i32(raw+OFF_NUMBODY), body_offset=rd_i32(raw+OFF_BODYIDX);
    if(body_count<=0||body_offset<=0||!range_ok((u32)body_offset,(u64)body_count*MDL_BODYPART_SIZE,size))
        return AETHER_ERR_NOT_FOUND;
    u32 tris=total_triangles(raw,size,body_count,body_offset);
    if(tris==0) return AETHER_ERR_NOT_FOUND;
    u64 verts64=(u64)tris*3u;
    if(verts64>100000000u) return AETHER_ERR_OUT_OF_MEM;

    aether_model_mesh_t *o=(aether_model_mesh_t*)calloc(1,sizeof*o);
    if(!o) return AETHER_ERR_OUT_OF_MEM;
    u32 cap=(u32)verts64;
    o->positions=(f32*)calloc((size_t)cap*3u,sizeof(f32));
    o->normals=(f32*)calloc((size_t)cap*3u,sizeof(f32));
    o->uvs=(f32*)calloc((size_t)cap*2u,sizeof(f32));
    o->bone_indices=(u8*)calloc(cap,1);
    o->indices=(u32*)calloc((size_t)tris*3u,sizeof(u32));
    if(!o->positions||!o->normals||!o->uvs||!o->bone_indices||!o->indices){
        aether_mdl_geometry_free(o);return AETHER_ERR_OUT_OF_MEM;
    }
    extract_first_texture(mdl,o);

    const f32 inf=1e30f;
    for(int k=0;k<3;++k){o->bounds_min[k]=inf;o->bounds_max[k]=-inf;}
    u32 vcur=0,icur=0;
    for(i32 bp=0;bp<body_count;++bp){
        u32 bo=(u32)body_offset+(u32)bp*MDL_BODYPART_SIZE;
        if(!range_ok(bo,MDL_BODYPART_SIZE,size))break;
        const mdl_bodypart_disk_t *b=(const mdl_bodypart_disk_t*)(raw+bo);
        if(b->num_models<=0||b->model_index<=0)continue;
        for(i32 mi=0;mi<b->num_models;++mi){
            u32 mo=(u32)b->model_index+(u32)mi*MDL_MODEL_SIZE;
            if(!range_ok(mo,MDL_MODEL_SIZE,size))break;
            const mdl_model_disk_t *m=(const mdl_model_disk_t*)(raw+mo);
            if(m->num_verts<=0||m->num_norms<=0||m->vert_info_index<=0||m->vert_index<=0||
               m->norm_info_index<=0||m->norm_index<=0||m->mesh_index<=0)continue;
            if(!range_ok((u32)m->vert_info_index,(u64)m->num_verts,size) ||
               !range_ok((u32)m->vert_index,(u64)m->num_verts*MDL_VERTEX_SIZE,size) ||
               !range_ok((u32)m->norm_info_index,(u64)m->num_norms,size) ||
               !range_ok((u32)m->norm_index,(u64)m->num_norms*MDL_VERTEX_SIZE,size)) continue;
            const u8 *vpos=raw+(u32)m->vert_index;
            const u8 *vbone=raw+(u32)m->vert_info_index;
            const u8 *npos=raw+(u32)m->norm_index;
            for(i32 mesh_i=0;mesh_i<m->num_meshes;++mesh_i){
                u32 xo=(u32)m->mesh_index+(u32)mesh_i*MDL_MESH_SIZE;
                if(!range_ok(xo,MDL_MESH_SIZE,size))break;
                const mdl_mesh_disk_t *mx=(const mdl_mesh_disk_t*)(raw+xo);
                if(mx->num_tris<=0||mx->tri_indexes<=0)continue;
                const u8 *p=raw+(u32)mx->tri_indexes,*end=raw+size;
                u32 skinref=(u32)(mx->skin_ref<0?0:mx->skin_ref);
                i32 skin_count=rd_i32(raw+192), skin_fams=rd_i32(raw+196), skinidx=rd_i32(raw+200);
                u32 tex_slot=skinref;
                if(skinidx>0&&skin_count>0&&skin_fams>0&&skinref<(u32)skin_count){
                    u32 sr_off=(u32)skinidx+(u32)skinref*2u;
                    if(range_ok(sr_off,2,size))tex_slot=(u32)rd_u16(raw+sr_off);
                }
                /* Current mesh is flattened to one texture; tex_slot is
                   retained in the UV decode decision for future materials. */
                (void)tex_slot;
                for(u32 groups=0;groups<65535u&&p+2<=end;++groups){
                    i16 sc=rd_i16(p);p+=2;if(sc==0)break;
                    bool fan=sc<0;u32 n=(u32)(fan?-sc:sc);
                    u64 bytes=(u64)n*MDL_COMMAND_VERTEX_SIZE;
                    if((u64)(end-p)<bytes)break;
                    if(n<3){p+=bytes;continue;}
                    for(u32 j=2;j<n;++j){
                        u32 seq[3];
                        if(fan){seq[0]=0;seq[1]=j-1;seq[2]=j;}
                        else if((j&1u)==0){seq[0]=j-2;seq[1]=j-1;seq[2]=j;}
                        else{seq[0]=j-1;seq[1]=j-2;seq[2]=j;}
                        u32 base=vcur;
                        for(int k=0;k<3;++k){
                            const u8 *cv=p+seq[k]*MDL_COMMAND_VERTEX_SIZE;
                            u16 vi=rd_u16(cv),ni=rd_u16(cv+2);
                            if(vi>=(u32)m->num_verts||ni>=(u32)m->num_norms||vcur>=cap)continue;
                            const u8 *vp=vpos+(u32)vi*MDL_VERTEX_SIZE;
                            const u8 *np=npos+(u32)ni*MDL_VERTEX_SIZE;
                            f32 px=rd_f32(vp),py=rd_f32(vp+4),pz=rd_f32(vp+8);
                            f32 nx=rd_f32(np),ny=rd_f32(np+4),nz=rd_f32(np+8);
                            i16 ss=rd_i16(cv+4),tt=rd_i16(cv+6);
                            o->positions[vcur*3+0]=px;o->positions[vcur*3+1]=py;o->positions[vcur*3+2]=pz;
                            o->normals[vcur*3+0]=nx;o->normals[vcur*3+1]=ny;o->normals[vcur*3+2]=nz;
                            o->uvs[vcur*2+0]=(o->texture_width>0)?(f32)ss/(f32)o->texture_width:0.0f;
                            o->uvs[vcur*2+1]=(o->texture_height>0)?1.0f-(f32)tt/(f32)o->texture_height:0.0f;
                            o->bone_indices[vcur]=(u8)(vbone[vi]);
                            const f32 pos[3]={px,py,pz};
                            for(int q=0;q<3;++q){if(pos[q]<o->bounds_min[q])o->bounds_min[q]=pos[q];if(pos[q]>o->bounds_max[q])o->bounds_max[q]=pos[q];}
                            ++vcur;
                        }
                        if(vcur>=base+3&&icur+3<=tris*3u){
                            o->indices[icur++]=base;o->indices[icur++]=base+1;o->indices[icur++]=base+2;
                        }
                    }
                    p+=bytes;
                }
            }
        }
    }
    o->vertex_count=vcur;o->triangle_count=icur/3u;
    if(!vcur||!o->triangle_count){aether_mdl_geometry_free(o);return AETHER_ERR_GENERIC;}
    for(int k=0;k<3;++k)o->bounds_center[k]=(o->bounds_min[k]+o->bounds_max[k])*0.5f;
    aether_log(AETHER_LOG_INFO,"mdl-geo","decoded MDL: %u verts, %u tris, UV=%s, texture=%ux%u",
               o->vertex_count,o->triangle_count,o->uvs?"yes":"no",o->texture_width,o->texture_height);
    *out_mesh=o;return AETHER_OK;
}
void aether_mdl_geometry_free(aether_model_mesh_t *m) {
    if (!m) return;
    free(m->positions);
    free(m->normals);
    free(m->uvs);
    free(m->bone_indices);
    free(m->indices);
    free(m->texture_rgba);
    free(m);
}
void aether_mdl_geometry_dump(const aether_model_mesh_t*m){
    if(!m)return;
    aether_log(AETHER_LOG_INFO,"mdl-geo","===== MDL MESH =====");
    aether_log(AETHER_LOG_INFO,"mdl-geo","verts=%u tris=%u texture=%ux%u",m->vertex_count,m->triangle_count,m->texture_width,m->texture_height);
    aether_log(AETHER_LOG_INFO,"mdl-geo","min=%.1f %.1f %.1f max=%.1f %.1f %.1f",m->bounds_min[0],m->bounds_min[1],m->bounds_min[2],m->bounds_max[0],m->bounds_max[1],m->bounds_max[2]);
}
