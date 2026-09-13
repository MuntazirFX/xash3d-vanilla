#ifndef AETHER_BSP_NAV_BUILDER_H
#define AETHER_BSP_NAV_BUILDER_H
#include "AetherNavMesh.h"
#include "../../bsp/AetherBSP.h"
#ifdef __cplusplus
extern "C" {
#endif

typedef struct aether_bsp_nav_build_config {
    f32 max_node_spacing;
    f32 max_step_height;
    f32 min_leaf_height;
    bool include_sky;
} aether_bsp_nav_build_config_t;

void aether_bsp_nav_build_config_default(aether_bsp_nav_build_config_t *cfg);
/* Builds a conservative walk graph from non-solid BSP leaf volumes. The graph
   is intentionally capped by AETHER_PATH_MAX_NODES. Returns generated nodes. */
u32 aether_bsp_nav_build(aethernavmesh_state_t *nav, const aether_bsp_t *bsp,
                         const aether_bsp_nav_build_config_t *cfg);
#ifdef __cplusplus
}
#endif
#endif
