#include "AetherBSPNavBuilder.h"
#include "../../player/AetherCollision.h"
#include <math.h>

void aether_bsp_nav_build_config_default(aether_bsp_nav_build_config_t *cfg) {
    if (!cfg) return;
    cfg->max_node_spacing = 192.0f;
    cfg->max_step_height = 48.0f;
    cfg->min_leaf_height = 32.0f;
    cfg->include_sky = false;
}

static bool usable_leaf_(const aether_bsp_leaf_t *leaf, const aether_bsp_nav_build_config_t *cfg) {
    if (!leaf || !cfg) return false;
    if (leaf->contents == AETHER_CONTENTS_SOLID) return false;
    if (!cfg->include_sky && leaf->contents == AETHER_CONTENTS_SKY) return false;
    const f32 h = (f32)leaf->maxs[2] - (f32)leaf->mins[2];
    return h >= cfg->min_leaf_height;
}

u32 aether_bsp_nav_build(aethernavmesh_state_t *nav, const aether_bsp_t *bsp,
                         const aether_bsp_nav_build_config_t *cfg_in) {
    if (!nav || !bsp || !aether_bsp_is_valid(bsp)) return 0;
    aether_bsp_nav_build_config_t local;
    if (!cfg_in) { aether_bsp_nav_build_config_default(&local); cfg_in = &local; }
    aetherpathfind_clear_graph(&nav->graph);
    nav->generated_nodes = 0;

    const u32 leaf_count = aether_bsp_leaf_count(bsp);
    for (u32 i = 0; i < leaf_count && nav->graph.node_count < AETHER_PATH_MAX_NODES; ++i) {
        const aether_bsp_leaf_t *leaf = aether_bsp_leaf_at(bsp, i);
        if (!usable_leaf_(leaf, cfg_in)) continue;
        const aether_vec3_t center = {
            ((f32)leaf->mins[0] + (f32)leaf->maxs[0]) * 0.5f,
            ((f32)leaf->mins[1] + (f32)leaf->maxs[1]) * 0.5f,
            (f32)leaf->mins[2] + 8.0f
        };
        if (aetherpathfind_add_node(&nav->graph, i + 1u, center) >= 0)
            nav->generated_nodes++;
    }

    const f32 max_d = cfg_in->max_node_spacing > 1.0f ? cfg_in->max_node_spacing : 192.0f;
    const f32 max_d2 = max_d * max_d;
    const f32 max_z = cfg_in->max_step_height >= 0.0f ? cfg_in->max_step_height : 48.0f;
    for (u32 a = 0; a < nav->graph.node_count; ++a) {
        for (u32 b = a + 1u; b < nav->graph.node_count; ++b) {
            const aether_vec3_t pa = nav->graph.nodes[a].position;
            const aether_vec3_t pb = nav->graph.nodes[b].position;
            const f32 dx=pa.x-pb.x, dy=pa.y-pb.y, dz=pa.z-pb.z;
            if (dx*dx + dy*dy + dz*dz > max_d2 || fabsf(dz) > max_z) continue;
            if (!aetherpathfind_add_link(&nav->graph, nav->graph.nodes[a].id,
                                         nav->graph.nodes[b].id, 0.0f)) continue;
            (void)aetherpathfind_add_link(&nav->graph, nav->graph.nodes[b].id,
                                          nav->graph.nodes[a].id, 0.0f);
            if (nav->graph.link_count >= AETHER_PATH_MAX_NODES * 6u) return nav->generated_nodes;
        }
    }
    return nav->generated_nodes;
}
