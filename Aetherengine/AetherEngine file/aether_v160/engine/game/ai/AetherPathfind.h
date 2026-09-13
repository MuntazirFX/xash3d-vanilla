#ifndef AETHER_AETHERPATHFIND_H
#define AETHER_AETHERPATHFIND_H

#include "../../core/AetherCore.h"
#include "../../core/AetherMath.h"

#ifdef __cplusplus
extern "C" {
#endif

#define AETHER_PATH_MAX_NODES 512
#define AETHER_PATH_MAX_RESULT 64

typedef struct aether_path_node {
    u32 id;
    aether_vec3_t position;
    u16 first_link;
    u16 link_count;
    bool enabled;
} aether_path_node_t;

typedef struct aether_path_link {
    u16 from;
    u16 to;
    f32 cost;
} aether_path_link_t;

typedef struct aether_pathfind_state {
    bool enabled;
    aether_path_node_t nodes[AETHER_PATH_MAX_NODES];
    aether_path_link_t links[AETHER_PATH_MAX_NODES * 6];
    u32 node_count;
    u32 link_count;
    u32 events;
    u32 searches;
    u32 successful_searches;
    u32 last_result_count;
    u16 last_result[AETHER_PATH_MAX_RESULT];
    char text[128];
} aether_pathfind_state_t;

void aetherpathfind_init(aether_pathfind_state_t *s);
void aetherpathfind_update(aether_pathfind_state_t *s, f32 dt);
void aetherpathfind_reset(aether_pathfind_state_t *s);
void aetherpathfind_event(aether_pathfind_state_t *s);

int aetherpathfind_add_node(aether_pathfind_state_t *s, u32 id, aether_vec3_t position);
bool aetherpathfind_add_link(aether_pathfind_state_t *s, u32 from_id, u32 to_id, f32 cost);
void aetherpathfind_clear_graph(aether_pathfind_state_t *s);
int aetherpathfind_nearest_node(const aether_pathfind_state_t *s, aether_vec3_t position, f32 max_distance);

/* Returns the number of node ids in out_path, or 0 when no route exists. */
u32 aetherpathfind_find(const aether_pathfind_state_t *s, u32 start_id, u32 goal_id,
                        u16 *out_path, u32 max_path);

#ifdef __cplusplus
}
#endif
#endif
