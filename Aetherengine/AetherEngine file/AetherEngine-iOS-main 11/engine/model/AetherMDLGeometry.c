/* AetherMDLGeometry.c — MDL v10 triangle-command decoding.
 * AetherEngine-iOS · Clean-room.
 *
 * GoldSrc studio meshes store geometry as triangle strip/fan command streams,
 * not as a flat u16[3*num_tris] index array. This implementation decodes that
 * stream and uses the on-disk studio vertex/normal stride of 16 bytes.
 */
#include "AetherMDLGeometry.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MDL_HEADER_SIZE       244u
#define MDL_MESH_SIZE          36u
#define MDL_MODEL_SIZE        108u
#define MDL_BODYPART_SIZE      76u
#define MDL_VERTEX_SIZE        16u
#define MDL_COMMAND_VERTEX_SIZE 8u /* vertex, normal, s, t = 4 x int16 */

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

#pragma pack(push, 1)
typedef struct mdl_mesh_disk {
    i32 num_tris;
    i32 tri_indexes;
    i32 skin_ref;
    i32 num_verts;
    i32 vert_info_index;
    i32 num_norms;
    i32 norm_info_index;
    i32 num_groups;
    i32 group_index;
} mdl_mesh_disk_t;

typedef struct mdl_model_disk {
    char name[64];
    i32 type;
    f32 bounding_radius;
    i32 num_meshes;
    i32 mesh_index;
    i32 num_verts;
    i32 vert_info_index;
    i32 num_norms;
    i32 norm_info_index;
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

static bool range_ok(u32 offset, u64 bytes, u32 size) {
    return offset <= size && bytes <= (u64)(size - offset);
}

/* Count triangles in one studio triangle command stream. */
static u32 command_triangles(const u8 *raw, u32 raw_size, i32 command_offset,
                             i32 expected_tris) {
    if (!raw || command_offset <= 0 || !range_ok((u32)command_offset, 2, raw_size)) return 0;
    const u8 *p = raw + (u32)command_offset;
    const u8 *end = raw + raw_size;
    u64 produced = 0;

    for (u32 groups = 0; groups < 65535u && p + 2 <= end; ++groups) {
        i16 count = rd_i16(p); p += 2;
        if (count == 0) break;
        u32 n = (u32)(count < 0 ? -count : count);
        u64 bytes = (u64)n * MDL_COMMAND_VERTEX_SIZE;
        if ((u64)(end - p) < bytes) break;
        if (n >= 3) produced += (u64)n - 2u;
        p += bytes;
        if (expected_tris > 0 && produced >= (u32)expected_tris) return (u32)produced;
    }
    return (u32)produced;
}

static u32 total_meshes_and_tris(const u8 *raw, u32 raw_size,
                                 i32 body_count, i32 body_offset) {
    u64 total = 0;
    for (i32 bp = 0; bp < body_count; ++bp) {
        u32 bo = (u32)body_offset + (u32)bp * MDL_BODYPART_SIZE;
        if (!range_ok(bo, MDL_BODYPART_SIZE, raw_size)) break;
        const mdl_bodypart_disk_t *b = (const mdl_bodypart_disk_t *)(raw + bo);
        if (b->num_models <= 0 || b->model_index <= 0) continue;
        for (i32 mi = 0; mi < b->num_models; ++mi) {
            u32 mo = (u32)b->model_index + (u32)mi * MDL_MODEL_SIZE;
            if (!range_ok(mo, MDL_MODEL_SIZE, raw_size)) break;
            const mdl_model_disk_t *m = (const mdl_model_disk_t *)(raw + mo);
            if (m->num_meshes <= 0 || m->mesh_index <= 0) continue;
            for (i32 mesh_i = 0; mesh_i < m->num_meshes; ++mesh_i) {
                u32 xo = (u32)m->mesh_index + (u32)mesh_i * MDL_MESH_SIZE;
                if (!range_ok(xo, MDL_MESH_SIZE, raw_size)) break;
                const mdl_mesh_disk_t *mesh = (const mdl_mesh_disk_t *)(raw + xo);
                if (mesh->num_tris <= 0) continue;
                u32 tris = command_triangles(raw, raw_size, mesh->tri_indexes, mesh->num_tris);
                if (tris > 0) total += tris;
            }
        }
    }
    return total > 0xFFFFFFFFu ? 0 : (u32)total;
}

aether_result_t aether_mdl_geometry_extract(const aether_mdl_t *mdl,
                                             aether_model_mesh_t **out_mesh) {
    if (!mdl || !out_mesh || !aether_mdl_is_valid(mdl)) return AETHER_ERR_INVALID_ARG;
    *out_mesh = NULL;

    u32 raw_size = 0;
    const u8 *raw = aether_mdl_raw_data(mdl, &raw_size);
    if (!raw || raw_size < MDL_HEADER_SIZE) return AETHER_ERR_INVALID_ARG;

    const i32 body_count = rd_i32(raw + 204);
    const i32 body_offset = rd_i32(raw + 208);
    if (body_count <= 0 || body_offset <= 0 || !range_ok((u32)body_offset, (u64)body_count * MDL_BODYPART_SIZE, raw_size))
        return AETHER_ERR_NOT_FOUND;

    const u32 total_tris = total_meshes_and_tris(raw, raw_size, body_count, body_offset);
    if (total_tris == 0) return AETHER_ERR_NOT_FOUND;
    const u64 total_verts64 = (u64)total_tris * 3u;
    if (total_verts64 > 100000000u) return AETHER_ERR_OUT_OF_MEM;

    aether_model_mesh_t *mesh_out = (aether_model_mesh_t *)calloc(1, sizeof *mesh_out);
    if (!mesh_out) return AETHER_ERR_OUT_OF_MEM;
    const u32 total_verts = (u32)total_verts64;
    mesh_out->positions = (f32 *)malloc((size_t)total_verts * 3u * sizeof(f32));
    mesh_out->normals   = (f32 *)malloc((size_t)total_verts * 3u * sizeof(f32));
    mesh_out->indices   = (u32 *)malloc((size_t)total_tris * 3u * sizeof(u32));
    if (!mesh_out->positions || !mesh_out->normals || !mesh_out->indices) {
        aether_mdl_geometry_free(mesh_out);
        return AETHER_ERR_OUT_OF_MEM;
    }

    const f32 inf = 1e30f;
    for (int k = 0; k < 3; ++k) {
        mesh_out->bounds_min[k] = inf;
        mesh_out->bounds_max[k] = -inf;
    }

    u32 vcur = 0, icur = 0;
    for (i32 bp = 0; bp < body_count; ++bp) {
        u32 bo = (u32)body_offset + (u32)bp * MDL_BODYPART_SIZE;
        if (!range_ok(bo, MDL_BODYPART_SIZE, raw_size)) break;
        const mdl_bodypart_disk_t *b = (const mdl_bodypart_disk_t *)(raw + bo);
        for (i32 mi = 0; mi < b->num_models; ++mi) {
            u32 mo = (u32)b->model_index + (u32)mi * MDL_MODEL_SIZE;
            if (!range_ok(mo, MDL_MODEL_SIZE, raw_size)) break;
            const mdl_model_disk_t *m = (const mdl_model_disk_t *)(raw + mo);
            if (m->num_verts <= 0 || m->num_norms <= 0 || m->vert_info_index <= 0 || m->norm_info_index <= 0) continue;
            if (!range_ok((u32)m->vert_info_index, (u64)m->num_verts * MDL_VERTEX_SIZE, raw_size) ||
                !range_ok((u32)m->norm_info_index, (u64)m->num_norms * MDL_VERTEX_SIZE, raw_size)) continue;
            const u8 *verts = raw + (u32)m->vert_info_index;
            const u8 *norms = raw + (u32)m->norm_info_index;

            for (i32 mesh_i = 0; mesh_i < m->num_meshes; ++mesh_i) {
                u32 xo = (u32)m->mesh_index + (u32)mesh_i * MDL_MESH_SIZE;
                if (!range_ok(xo, MDL_MESH_SIZE, raw_size)) break;
                const mdl_mesh_disk_t *mx = (const mdl_mesh_disk_t *)(raw + xo);
                if (mx->num_tris <= 0 || mx->tri_indexes <= 0) continue;
                if (!range_ok((u32)mx->tri_indexes, 2, raw_size)) continue;

                const u8 *p = raw + (u32)mx->tri_indexes;
                const u8 *end = raw + raw_size;
                for (u32 groups = 0; groups < 65535u && p + 2 <= end; ++groups) {
                    i16 signed_count = rd_i16(p); p += 2;
                    if (signed_count == 0) break;
                    bool fan = signed_count < 0;
                    u32 n = (u32)(fan ? -signed_count : signed_count);
                    u64 bytes = (u64)n * MDL_COMMAND_VERTEX_SIZE;
                    if ((u64)(end - p) < bytes) break;
                    if (n < 3) { p += bytes; continue; }

                    /* Decode the command vertices first. Each triangle is
                       expanded to three vertices so no strip topology state
                       leaks into the renderer. */
                    for (u32 j = 2; j < n; ++j) {
                        u32 seq[3];
                        if (fan) { seq[0] = 0; seq[1] = j - 1; seq[2] = j; }
                        else if ((j & 1u) == 0u) { seq[0] = j - 2; seq[1] = j - 1; seq[2] = j; }
                        else { seq[0] = j - 1; seq[1] = j - 2; seq[2] = j; }

                        for (int k = 0; k < 3; ++k) {
                            const u8 *v = p + seq[k] * MDL_COMMAND_VERTEX_SIZE;
                            u16 vi = rd_u16(v + 0);
                            u16 ni = rd_u16(v + 2);
                            if (vi >= (u32)m->num_verts || ni >= (u32)m->num_norms || vcur >= total_verts) {
                                continue;
                            }
                            const u8 *vp = verts + (u32)vi * MDL_VERTEX_SIZE;
                            const u8 *np = norms + (u32)ni * MDL_VERTEX_SIZE;
                            f32 px = rd_f32(vp+0), py = rd_f32(vp+4), pz = rd_f32(vp+8);
                            f32 nx = rd_f32(np+0), ny = rd_f32(np+4), nz = rd_f32(np+8);
                            mesh_out->positions[vcur*3+0] = px;
                            mesh_out->positions[vcur*3+1] = py;
                            mesh_out->positions[vcur*3+2] = pz;
                            mesh_out->normals[vcur*3+0] = nx;
                            mesh_out->normals[vcur*3+1] = ny;
                            mesh_out->normals[vcur*3+2] = nz;
                            const f32 pos[3] = { px, py, pz };
                            for (int q = 0; q < 3; ++q) {
                                if (pos[q] < mesh_out->bounds_min[q]) mesh_out->bounds_min[q] = pos[q];
                                if (pos[q] > mesh_out->bounds_max[q]) mesh_out->bounds_max[q] = pos[q];
                            }
                            ++vcur;
                        }
                        if (icur + 3 <= total_tris * 3u) {
                            mesh_out->indices[icur++] = vcur - 3u;
                            mesh_out->indices[icur++] = vcur - 2u;
                            mesh_out->indices[icur++] = vcur - 1u;
                        }
                    }
                    p += bytes;
                }
            }
        }
    }

    mesh_out->vertex_count = vcur;
    mesh_out->triangle_count = icur / 3u;
    if (vcur == 0 || mesh_out->triangle_count == 0) {
        aether_mdl_geometry_free(mesh_out);
        return AETHER_ERR_GENERIC;
    }
    for (int k = 0; k < 3; ++k)
        mesh_out->bounds_center[k] = (mesh_out->bounds_min[k] + mesh_out->bounds_max[k]) * 0.5f;

    aether_log(AETHER_LOG_INFO, "mdl-geo", "decoded command stream: %u verts, %u tris",
               mesh_out->vertex_count, mesh_out->triangle_count);
    *out_mesh = mesh_out;
    return AETHER_OK;
}

void aether_mdl_geometry_free(aether_model_mesh_t *m) {
    if (!m) return;
    free(m->positions);
    free(m->normals);
    free(m->indices);
    free(m);
}

void aether_mdl_geometry_dump(const aether_model_mesh_t *m) {
    if (!m) return;
    aether_log(AETHER_LOG_INFO, "mdl-geo", "===== MDL MESH =====");
    aether_log(AETHER_LOG_INFO, "mdl-geo", "  verts: %u", m->vertex_count);
    aether_log(AETHER_LOG_INFO, "mdl-geo", "  tris : %u", m->triangle_count);
    aether_log(AETHER_LOG_INFO, "mdl-geo", "  min  : %.1f %.1f %.1f", m->bounds_min[0], m->bounds_min[1], m->bounds_min[2]);
    aether_log(AETHER_LOG_INFO, "mdl-geo", "  max  : %.1f %.1f %.1f", m->bounds_max[0], m->bounds_max[1], m->bounds_max[2]);
    aether_log(AETHER_LOG_INFO, "mdl-geo", "====================");
}
