#ifndef AETHER_AETHERNAVMESH_H
#define AETHER_AETHERNAVMESH_H
#include "../../core/AetherCore.h"
#include "../../core/AetherMath.h"
#include "AetherPathfind.h"
#ifdef __cplusplus
extern "C" {
#endif

typedef struct aethernavmesh_state {
    bool enabled;
    f32 value;
    u32 events;
    u32 generated_nodes;
    f32 node_radius;
    aether_pathfind_state_t graph;
    char text[128];
} aethernavmesh_state_t;

void aethernavmesh_init(aethernavmesh_state_t *s);
void aethernavmesh_update(aethernavmesh_state_t *s, f32 dt);
void aethernavmesh_reset(aethernavmesh_state_t *s);
void aethernavmesh_event(aethernavmesh_state_t *s);

int aethernavmesh_add_node(aethernavmesh_state_t *s, u32 id, aether_vec3_t position);
bool aethernavmesh_connect(aethernavmesh_state_t *s, u32 a, u32 b);
int aethernavmesh_nearest(const aethernavmesh_state_t *s, aether_vec3_t position, f32 max_distance);
u32 aethernavmesh_route(const aethernavmesh_state_t *s, u32 start_id, u32 goal_id, u16 *out, u32 max_out);

#ifdef __cplusplus
}
#endif
#endif
