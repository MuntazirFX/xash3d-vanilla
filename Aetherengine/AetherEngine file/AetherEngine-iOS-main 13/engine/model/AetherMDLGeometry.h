/* AetherMDLGeometry.h — GoldSrc MDL v10 geometry/material extraction.
 * AetherEngine-iOS · Clean-room.
 */
#ifndef AETHER_MDL_GEOMETRY_H
#define AETHER_MDL_GEOMETRY_H

#include "AetherMDL.h"
#include "../core/AetherMath.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct aether_model_mesh {
    /* Expanded triangle list. Per vertex: position, normal, UV and source bone. */
    f32 *positions;      /* 3 floats * vertex_count */
    f32 *normals;        /* 3 floats * vertex_count */
    f32 *uvs;            /* 2 floats * vertex_count, normalized 0..1 */
    u8  *bone_indices;   /* 1 byte * vertex_count */
    u32 *indices;        /* 3 indices * triangle_count */
    u32  vertex_count;
    u32  triangle_count;

    /* First embedded MDL texture, when available. */
    u8  *texture_rgba;   /* width * height * 4 */
    u32  texture_width;
    u32  texture_height;

    f32  bounds_min[3];
    f32  bounds_max[3];
    f32  bounds_center[3];
} aether_model_mesh_t;

aether_result_t aether_mdl_geometry_extract(const aether_mdl_t *mdl,
                                             aether_model_mesh_t **out_mesh);
void            aether_mdl_geometry_free(aether_model_mesh_t *m);
void            aether_mdl_geometry_dump(const aether_model_mesh_t *m);

#ifdef __cplusplus
}
#endif
#endif
