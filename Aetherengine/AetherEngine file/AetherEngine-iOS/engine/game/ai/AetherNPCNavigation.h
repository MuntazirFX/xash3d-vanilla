#ifndef AETHER_NPC_NAVIGATION_H
#define AETHER_NPC_NAVIGATION_H

#include "AetherPathfind.h"
#include "../monsters/AetherMonsterBase.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct aether_npc_navigation {
    bool enabled;
    bool has_route;
    u32 target_node;
    u16 path[AETHER_PATH_MAX_RESULT];
    u32 path_count;
    u32 path_index;
    f32 waypoint_radius;
    f32 repath_interval;
    f32 repath_timer;
    u32 routes_built;
    u32 waypoints_reached;
} aether_npc_navigation_t;

void aether_npc_navigation_init(aether_npc_navigation_t *nav);
void aether_npc_navigation_reset(aether_npc_navigation_t *nav);
bool aether_npc_navigation_build(aether_npc_navigation_t *nav,
                                  const aether_pathfind_state_t *graph,
                                  aether_vec3_t npc_position,
                                  aether_vec3_t target_position,
                                  f32 max_search_distance);
bool aether_npc_navigation_update(aether_npc_navigation_t *nav,
                                   const aether_pathfind_state_t *graph,
                                   aether_monster_t *monster,
                                   aether_vec3_t target_position,
                                   f32 dt);
bool aether_npc_navigation_has_route(const aether_npc_navigation_t *nav);

#ifdef __cplusplus
}
#endif
#endif
