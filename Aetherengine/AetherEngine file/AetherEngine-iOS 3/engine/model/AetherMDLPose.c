/* AetherMDLPose.c — GoldSrc skeletal animation sampler and CPU skinning. */
#include "AetherMDLPose.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MDL_HEADER_SIZE 244u
#define MDL_BONE_SIZE 112u
#define MDL_SEQDESC_SIZE 176u
#define MDL_ANIM_SIZE 12u
#define HDR_NUMBONES 140u
#define HDR_BONEIDX 144u
#define HDR_NUMSEQ 164u
#define HDR_SEQIDX 168u
#define HDR_SEQGROUPIDX 176u
#define HDR_NUMSEQGROUPS 172u

/* GoldSrc sequence descriptor offsets. */
#define SEQ_FPS 32u
#define SEQ_FLAGS 36u
#define SEQ_NUMEVENTS 48u
#define SEQ_EVENTINDEX 52u
#define SEQ_NUMFRAMES 56u
#define SEQ_NUMPIVOTS 60u
#define SEQ_PIVOTINDEX 64u
#define SEQ_MOTIONTYPE 68u
#define SEQ_MOTIONBONE 72u
#define SEQ_LINEAR 76u
#define SEQ_AUTOMOVEPOS 88u
#define SEQ_AUTOMOVEANGLE 92u
#define SEQ_BBMIN 96u
#define SEQ_BBMAX 108u
#define SEQ_NUMBLENDS 120u
#define SEQ_ANIMINDEX 124u
#define SEQ_BLENDTYPE 128u
#define SEQ_BLENDSTART 136u
#define SEQ_BLENDEND 144u
#define SEQ_BLENDPARENT 152u
#define SEQ_GROUP 156u

/* GoldSrc bone offsets. */
#define BONE_PARENT 32u
#define BONE_FLAGS 36u
#define BONE_CONTROLLER 40u
#define BONE_VALUE 64u
#define BONE_SCALE 88u

#define STUDIO_X 0x0001
#define STUDIO_Y 0x0002
#define STUDIO_Z 0x0004
#define STUDIO_XR 0x0008
#define STUDIO_YR 0x0010
#define STUDIO_ZR 0x0020
#define STUDIO_LX 0x0040
#define STUDIO_LY 0x0080
#define STUDIO_LZ 0x0100

static u16 rd_u16(const u8 *p) {
    return (u16)((u16)p[0] | ((u16)p[1] << 8));
}
static i16 rd_i16(const u8 *p) { return (i16)rd_u16(p); }
static i32 rd_i32(const u8 *p) {
    return (i32)((u32)p[0] | ((u32)p[1] << 8) | ((u32)p[2] << 16) | ((u32)p[3] << 24));
}
static f32 rd_f32(const u8 *p) {
    u32 x = (u32)p[0] | ((u32)p[1] << 8) | ((u32)p[2] << 16) | ((u32)p[3] << 24);
    f32 f; memcpy(&f, &x, sizeof f); return f;
}
static bool range_ok(u32 off, u64 len, u32 size) {
    return (u64)off <= (u64)size && len <= (u64)size - (u64)off;
}

static void quat_identity(f32 q[4]) { q[0]=q[1]=q[2]=0.0f; q[3]=1.0f; }

static void quat_normalize(f32 q[4]) {
    f32 n = sqrtf(q[0]*q[0]+q[1]*q[1]+q[2]*q[2]+q[3]*q[3]);
    if (n < 1e-8f) { quat_identity(q); return; }
    f32 s=1.0f/n; q[0]*=s;q[1]*=s;q[2]*=s;q[3]*=s;
}

static void quat_from_euler_deg(const f32 a[3], f32 q[4]) {
    const f32 p=a[0]*(f32)(AETHER_PI/180.0), y=a[1]*(f32)(AETHER_PI/180.0), r=a[2]*(f32)(AETHER_PI/180.0);
    const f32 sp=sinf(p*0.5f), cp=cosf(p*0.5f);
    const f32 sy=sinf(y*0.5f), cy=cosf(y*0.5f);
    const f32 sr=sinf(r*0.5f), cr=cosf(r*0.5f);
    q[0]=sp*cy*cr-cp*sy*sr;
    q[1]=cp*sy*cr+sp*cy*sr;
    q[2]=cp*cy*sr-sp*sy*cr;
    q[3]=cp*cy*cr+sp*sy*sr;
    quat_normalize(q);
}

static void quat_slerp(const f32 a[4], const f32 b[4], f32 t, f32 out[4]) {
    f32 bb[4]={b[0],b[1],b[2],b[3]};
    f32 d=a[0]*bb[0]+a[1]*bb[1]+a[2]*bb[2]+a[3]*bb[3];
    if(d<0.0f){d=-d;bb[0]=-bb[0];bb[1]=-bb[1];bb[2]=-bb[2];bb[3]=-bb[3];}
    if(d>0.9995f){for(int i=0;i<4;++i)out[i]=a[i]+t*(bb[i]-a[i]);quat_normalize(out);return;}
    f32 theta=acosf(fmaxf(-1.0f,fminf(1.0f,d))), st=sinf(theta);
    if(fabsf(st)<1e-6f){memcpy(out,a,4*sizeof(f32));return;}
    f32 w1=sinf((1.0f-t)*theta)/st, w2=sinf(t*theta)/st;
    for(int i=0;i<4;++i)out[i]=a[i]*w1+bb[i]*w2;
    quat_normalize(out);
}

static aether_mat4_t mat_from_quat_pos(const f32 q[4], const f32 p[3]) {
    const f32 x=q[0],y=q[1],z=q[2],w=q[3];
    aether_mat4_t m=aether_mat4_identity();
    m.m[0]=1-2*(y*y+z*z); m.m[4]=2*(x*y-z*w);   m.m[8]=2*(x*z+y*w);
    m.m[1]=2*(x*y+z*w);   m.m[5]=1-2*(x*x+z*z); m.m[9]=2*(y*z-x*w);
    m.m[2]=2*(x*z-y*w);   m.m[6]=2*(y*z+x*w);   m.m[10]=1-2*(x*x+y*y);
    m.m[12]=p[0];m.m[13]=p[1];m.m[14]=p[2];
    return m;
}

static void transform_point(const aether_mat4_t *m, const f32 p[3], f32 out[3]) {
    out[0]=m->m[0]*p[0]+m->m[4]*p[1]+m->m[8]*p[2]+m->m[12];
    out[1]=m->m[1]*p[0]+m->m[5]*p[1]+m->m[9]*p[2]+m->m[13];
    out[2]=m->m[2]*p[0]+m->m[6]*p[1]+m->m[10]*p[2]+m->m[14];
}
static void transform_normal(const aether_mat4_t *m, const f32 p[3], f32 out[3]) {
    out[0]=m->m[0]*p[0]+m->m[4]*p[1]+m->m[8]*p[2];
    out[1]=m->m[1]*p[0]+m->m[5]*p[1]+m->m[9]*p[2];
    out[2]=m->m[2]*p[0]+m->m[6]*p[1]+m->m[10]*p[2];
    f32 n=sqrtf(out[0]*out[0]+out[1]*out[1]+out[2]*out[2]);
    if(n>1e-7f){out[0]/=n;out[1]/=n;out[2]/=n;}
}

/* Decode one compressed animation channel. The format stores runs of
   valid samples followed by total samples. */
static f32 sample_channel(const u8 *raw, u32 size, u32 start, u32 frame, f32 frac) {
    if(!range_ok(start,2,size)) return 0.0f;
    u32 off=start;
    u32 k=frame;
    for(u32 guard=0;guard<4096u;++guard){
        if(!range_ok(off,2,size)) return 0.0f;
        u8 valid=raw[off], total=raw[off+1];
        if(total==0) return 0.0f;
        if(total<valid) k=0;
        if(total>k){
            if(k<valid){
                u32 v1=off+2u+(u32)k*2u;
                if(!range_ok(v1,2,size)) return 0.0f;
                f32 a=(f32)rd_i16(raw+v1);
                f32 b=a;
                if(k+1u<valid){u32 v2=v1+2u;if(range_ok(v2,2,size))b=(f32)rd_i16(raw+v2);}
                else if(k+1u>=total){u32 v2=off+2u+(u32)(valid+1u)*2u;if(range_ok(v2,2,size))b=(f32)rd_i16(raw+v2);}
                return a+(b-a)*frac;
            }
            u32 last=off+2u+(u32)valid*2u;
            if(!range_ok(last,2,size)) return 0.0f;
            f32 a=(f32)rd_i16(raw+last), b=a;
            if(k+1u>=total){u32 next=last+2u;if(range_ok(next,2,size))b=(f32)rd_i16(raw+next);}
            return a+(b-a)*frac;
        }
        k-=total;
        u32 next=off+2u+(u32)(valid+1u)*2u;
        if(next<=off) return 0.0f;
        off=next;
    }
    return 0.0f;
}

static bool read_bone_defaults(const u8 *raw,u32 size,u32 bone_index,u32 i,
                               i32 *parent,i32 controllers[6],f32 value[6],f32 scale[6]){
    u64 off=(u64)bone_index+(u64)i*MDL_BONE_SIZE;
    if(off>UINT32_MAX||!range_ok((u32)off,MDL_BONE_SIZE,size))return false;
    const u8 *p=raw+(u32)off;
    *parent=rd_i32(p+BONE_PARENT);
    for(int j=0;j<6;++j)controllers[j]=rd_i32(p+BONE_CONTROLLER+(u32)j*4u);
    for(int j=0;j<6;++j)value[j]=rd_f32(p+BONE_VALUE+(u32)j*4u);
    for(int j=0;j<6;++j)scale[j]=rd_f32(p+BONE_SCALE+(u32)j*4u);
    return true;
}

static bool sample_blend(const u8 *raw,u32 size,u32 bone_index,u32 bone_count,
                         u32 anim_base,u32 frame,f32 frac,f32 out_pos[][3],f32 out_q[][4]){
    for(u32 i=0;i<bone_count;++i){
        i32 parent; i32 controllers[6]; f32 value[6],scale[6];
        if(!read_bone_defaults(raw,size,bone_index,i,&parent,controllers,value,scale))return false;
        (void)parent;(void)controllers;
        u64 ao=(u64)anim_base+(u64)i*MDL_ANIM_SIZE;
        if(ao>UINT32_MAX||!range_ok((u32)ao,MDL_ANIM_SIZE,size))return false;
        const u8 *a=raw+(u32)ao;
        for(int j=0;j<3;++j){
            u16 rel=rd_u16(a+j*2);
            if(rel) value[j]+=sample_channel(raw,size,(u32)ao+rel,frame,frac)*scale[j];
            out_pos[i][j]=value[j];
        }
        f32 ang[3];
        for(int j=0;j<3;++j){
            u16 rel=rd_u16(a+(j+3)*2);
            ang[j]=value[j+3];
            if(rel) ang[j]+=sample_channel(raw,size,(u32)ao+rel,frame,frac)*scale[j+3];
        }
        quat_from_euler_deg(ang,out_q[i]);
    }
    return true;
}

void aether_mdl_pose_init(aether_mdl_pose_t *pose){if(pose)memset(pose,0,sizeof*pose);}
void aether_mdl_pose_free(aether_mdl_pose_t *pose){if(!pose)return;free(pose->bones);memset(pose,0,sizeof*pose);}

static f32 blend_factor(f32 value,f32 start,f32 end){
    if(fabsf(end-start)<1e-6f)return 0.0f;
    f32 t=(value-start)/(end-start);return t<0?0:(t>1?1:t);
}

aether_result_t aether_mdl_pose_build(const aether_mdl_t *mdl,i32 sequence,f32 frame,f32 blend0,f32 blend1,aether_mdl_pose_t *out){
    if(!mdl||!out||!aether_mdl_is_valid(mdl))return AETHER_ERR_INVALID_ARG;
    aether_mdl_pose_free(out);
    u32 size=0;const u8 *raw=aether_mdl_raw_data(mdl,&size);
    if(!raw||size<MDL_HEADER_SIZE)return AETHER_ERR_INVALID_ARG;
    i32 bones=rd_i32(raw+HDR_NUMBONES),boneidx=rd_i32(raw+HDR_BONEIDX),seqs=rd_i32(raw+HDR_NUMSEQ),seqidx=rd_i32(raw+HDR_SEQIDX);
    if(bones<=0||bones>(i32)AETHER_MDL_POSE_MAX_BONES||boneidx<=0||seqs<=0||sequence<0||sequence>=seqs||seqidx<=0)return AETHER_ERR_NOT_FOUND;
    if(!range_ok((u32)boneidx,(u64)bones*MDL_BONE_SIZE,size)||!range_ok((u32)seqidx,(u64)seqs*MDL_SEQDESC_SIZE,size))return AETHER_ERR_GENERIC;
    const u8 *s=raw+(u32)seqidx+(u32)sequence*MDL_SEQDESC_SIZE;
    i32 numframes=rd_i32(s+SEQ_NUMFRAMES),numblends=rd_i32(s+SEQ_NUMBLENDS),animindex=rd_i32(s+SEQ_ANIMINDEX),seqgroup=rd_i32(s+SEQ_GROUP);
    if(numframes<1) numframes=1;
    if(numblends<1) numblends=1;
    if(seqgroup!=0){
        /* External sequence groups need the game's filesystem loader; keeping
           this explicit prevents silently reading unrelated bytes as animation. */
        return AETHER_ERR_UNSUPPORTED;
    }
    if(animindex<=0)return AETHER_ERR_NOT_FOUND;
    if(frame<0)frame=0;
    if(numframes>1){f32 maxf=(f32)(numframes-1);if(frame>maxf)frame=maxf;}
    u32 f0=(u32)floorf(frame);f32 frac=frame-(f32)f0;
    if(numframes<=1){f0=0;frac=0;}
    f32 pos0[AETHER_MDL_POSE_MAX_BONES][3],q0[AETHER_MDL_POSE_MAX_BONES][4];
    f32 pos1[AETHER_MDL_POSE_MAX_BONES][3],q1[AETHER_MDL_POSE_MAX_BONES][4];
    memset(pos0,0,sizeof pos0);memset(q0,0,sizeof q0);memset(pos1,0,sizeof pos1);memset(q1,0,sizeof q1);
    u32 blend_count=(u32)numblends;if(blend_count>4)blend_count=1;
    u32 block=(u32)animindex;
    if(!sample_blend(raw,size,(u32)boneidx,(u32)bones,block,f0,frac,pos0,q0))return AETHER_ERR_GENERIC;
    if(blend_count>=2){
        u32 b1=block+(u32)bones*MDL_ANIM_SIZE;
        if(!sample_blend(raw,size,(u32)boneidx,(u32)bones,b1,f0,frac,pos1,q1))return AETHER_ERR_GENERIC;
        f32 t=blend_factor(blend0,rd_f32(s+SEQ_BLENDSTART),rd_f32(s+SEQ_BLENDEND));
        for(i32 i=0;i<bones;++i){for(int j=0;j<3;++j)pos0[i][j]=pos0[i][j]*(1-t)+pos1[i][j]*t;f32 qq[4];quat_slerp(q0[i],q1[i],t,qq);memcpy(q0[i],qq,sizeof qq);}
    }
    aether_mdl_bone_pose_t *bp=(aether_mdl_bone_pose_t*)calloc((size_t)bones,sizeof*bp);if(!bp)return AETHER_ERR_OUT_OF_MEM;
    for(i32 i=0;i<bones;++i){memcpy(bp[i].position,pos0[i],sizeof bp[i].position);memcpy(bp[i].quaternion,q0[i],sizeof bp[i].quaternion);aether_mat4_t local=mat_from_quat_pos(bp[i].quaternion,bp[i].position);i32 parent=rd_i32(raw+(u32)boneidx+(u32)i*MDL_BONE_SIZE+BONE_PARENT);if(parent>=0&&parent<i)bp[i].matrix=aether_mat4_multiply(bp[parent].matrix,local);else bp[i].matrix=local;}
    out->bones=bp;out->bone_count=(u32)bones;out->sequence=sequence;out->frame=frame;out->blend[0]=blend0;out->blend[1]=blend1;
    aether_log(AETHER_LOG_INFO,"mdl-pose","sequence=%d frame=%.3f bones=%u blends=%d",sequence,frame,out->bone_count,numblends);
    return AETHER_OK;
}

const aether_mdl_bone_pose_t *aether_mdl_pose_bone_at(const aether_mdl_pose_t *pose,u32 index){return pose&&pose->bones&&index<pose->bone_count?&pose->bones[index]:NULL;}

aether_result_t aether_mdl_pose_skin_mesh(const aether_model_mesh_t *mesh,const aether_mdl_pose_t *pose,f32 *out_positions,f32 *out_normals,u32 max_vertices){
    if(!mesh||!pose||!out_positions||!out_normals||!mesh->positions||!mesh->normals||!mesh->bone_indices)return AETHER_ERR_INVALID_ARG;
    if(max_vertices<mesh->vertex_count)return AETHER_ERR_OUT_OF_MEM;
    for(u32 i=0;i<mesh->vertex_count;++i){u32 b=mesh->bone_indices[i];if(b>=pose->bone_count)b=0;transform_point(&pose->bones[b].matrix,mesh->positions+i*3,out_positions+i*3);transform_normal(&pose->bones[b].matrix,mesh->normals+i*3,out_normals+i*3);}
    return AETHER_OK;
}

void aether_mdl_pose_dump(const aether_mdl_pose_t *pose){if(!pose)return;aether_log(AETHER_LOG_INFO,"mdl-pose","pose: sequence=%d frame=%.3f bones=%u",pose->sequence,pose->frame,pose->bone_count);}
