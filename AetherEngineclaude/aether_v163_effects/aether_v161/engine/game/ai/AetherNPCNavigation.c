#include "AetherNPCNavigation.h"
#include <math.h>
#include <string.h>

static f32 dist3_(aether_vec3_t a, aether_vec3_t b) {
    f32 x=a.x-b.x, y=a.y-b.y, z=a.z-b.z;
    return sqrtf(x*x+y*y+z*z);
}

void aether_npc_navigation_init(aether_npc_navigation_t *nav) {
    if (!nav) return;
    memset(nav, 0, sizeof *nav);
    nav->enabled = true;
    nav->waypoint_radius = 20.0f;
    nav->repath_interval = 0.35f;
}

void aether_npc_navigation_reset(aether_npc_navigation_t *nav) {
    if (!nav) return;
    const bool enabled=nav->enabled;
    aether_npc_navigation_init(nav);
    nav->enabled=enabled;
}

bool aether_npc_navigation_build(aether_npc_navigation_t *nav,
                                 const aether_pathfind_state_t *graph,
                                 aether_vec3_t npc_position,
                                 aether_vec3_t target_position,
                                 f32 max_search_distance) {
    if (!nav || !graph || !nav->enabled) return false;
    const int start=aetherpathfind_nearest_node(graph,npc_position,max_search_distance);
    const int goal=aetherpathfind_nearest_node(graph,target_position,max_search_distance);
    if (start < 0 || goal < 0) {
        nav->has_route=false; nav->path_count=0; nav->path_index=0; return false;
    }
    u16 tmp[AETHER_PATH_MAX_RESULT];
    const u32 count=aetherpathfind_find(graph,graph->nodes[start].id,graph->nodes[goal].id,
                                        tmp,AETHER_PATH_MAX_RESULT);
    if (!count) {
        nav->has_route=false; nav->path_count=0; nav->path_index=0; return false;
    }
    memcpy(nav->path,tmp,count*sizeof(tmp[0]));
    nav->path_count=count;
    nav->path_index=(count > 1u) ? 1u : 0u;
    nav->target_node=graph->nodes[goal].id;
    nav->has_route=true;
    nav->routes_built++;
    return true;
}

static const aether_path_node_t *node_by_id_(const aether_pathfind_state_t *g,u32 id) {
    if (!g || !id) return NULL;
    for (u32 i=0;i<g->node_count;i++) if(g->nodes[i].id==id) return &g->nodes[i];
    return NULL;
}

bool aether_npc_navigation_update(aether_npc_navigation_t *nav,
                                  const aether_pathfind_state_t *graph,
                                  aether_monster_t *monster,
                                  aether_vec3_t target_position,
                                  f32 dt) {
    if (!nav || !graph || !monster || !monster->alive || !nav->enabled) return false;
    if (dt < 0) dt=0;
    if (nav->repath_timer > 0) nav->repath_timer -= dt;

    if (!nav->has_route || nav->repath_timer <= 0) {
        if (!aether_npc_navigation_build(nav,graph,monster->position,target_position,INFINITY)) return false;
        nav->repath_timer=nav->repath_interval;
    }

    if (nav->path_index >= nav->path_count) { nav->has_route=false; return false; }
    const aether_path_node_t *wp=node_by_id_(graph,nav->path[nav->path_index]);
    if (!wp) { nav->has_route=false; return false; }

    f32 d=dist3_(monster->position,wp->position);
    if (d <= nav->waypoint_radius) {
        nav->path_index++;
        nav->waypoints_reached++;
        if (nav->path_index >= nav->path_count) {
            nav->has_route=false;
            monster->velocity=(aether_vec3_t){0,0,0};
            return false;
        }
        wp=node_by_id_(graph,nav->path[nav->path_index]);
        if (!wp) { nav->has_route=false; return false; }
        d=dist3_(monster->position,wp->position);
    }

    aether_vec3_t delta={wp->position.x-monster->position.x,
                         wp->position.y-monster->position.y,
                         wp->position.z-monster->position.z};
    const f32 len=sqrtf(delta.x*delta.x+delta.y*delta.y+delta.z*delta.z);
    if (len <= 0.001f) return true;
    const f32 speed=monster->speed;
    const f32 inv=1.0f/len;
    monster->velocity.x=delta.x*inv*speed;
    monster->velocity.y=delta.y*inv*speed;
    monster->velocity.z=delta.z*inv*speed;
    monster->position.x += monster->velocity.x*dt;
    monster->position.y += monster->velocity.y*dt;
    monster->position.z += monster->velocity.z*dt;
    return true;
}

bool aether_npc_navigation_has_route(const aether_npc_navigation_t *nav) {
    return nav && nav->enabled && nav->has_route && nav->path_index < nav->path_count;
}
