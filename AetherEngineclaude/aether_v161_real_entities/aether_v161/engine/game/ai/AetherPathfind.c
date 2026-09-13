#include "AetherPathfind.h"
#include <math.h>
#include <string.h>

static f32 dist3(aether_vec3_t a, aether_vec3_t b) {
    const f32 x = a.x-b.x, y = a.y-b.y, z = a.z-b.z;
    return sqrtf(x*x+y*y+z*z);
}

static int node_index(const aether_pathfind_state_t *s, u32 id) {
    if (!s) return -1;
    for (u32 i=0; i<s->node_count; ++i) if (s->nodes[i].id == id) return (int)i;
    return -1;
}

void aetherpathfind_init(aether_pathfind_state_t *s) {
    if (!s) return;
    memset(s, 0, sizeof *s);
    s->enabled = true;
    aether_str_copy(s->text, sizeof s->text, "A* pathfinding ready");
}

void aetherpathfind_clear_graph(aether_pathfind_state_t *s) {
    if (!s) return;
    s->node_count = 0;
    s->link_count = 0;
    s->last_result_count = 0;
    memset(s->last_result, 0, sizeof s->last_result);
}

void aetherpathfind_reset(aether_pathfind_state_t *s) {
    if (!s) return;
    const bool enabled = s->enabled;
    aetherpathfind_init(s);
    s->enabled = enabled;
}

void aetherpathfind_update(aether_pathfind_state_t *s, f32 dt) {
    if (!s || !s->enabled) return;
    if (dt > 0) s->events += 0;
}

void aetherpathfind_event(aether_pathfind_state_t *s) { if (s) s->events++; }

int aetherpathfind_add_node(aether_pathfind_state_t *s, u32 id, aether_vec3_t position) {
    if (!s || !s->enabled || id == 0) return -1;
    const int existing = node_index(s, id);
    if (existing >= 0) { s->nodes[existing].position = position; s->nodes[existing].enabled = true; return existing; }
    if (s->node_count >= AETHER_PATH_MAX_NODES) return -1;
    const u32 i = s->node_count++;
    s->nodes[i].id = id;
    s->nodes[i].position = position;
    s->nodes[i].first_link = 0;
    s->nodes[i].link_count = 0;
    s->nodes[i].enabled = true;
    return (int)i;
}

bool aetherpathfind_add_link(aether_pathfind_state_t *s, u32 from_id, u32 to_id, f32 cost) {
    if (!s || !s->enabled || s->link_count >= AETHER_PATH_MAX_NODES*6) return false;
    const int from = node_index(s, from_id), to = node_index(s, to_id);
    if (from < 0 || to < 0) return false;
    if (cost <= 0) cost = dist3(s->nodes[from].position, s->nodes[to].position);
    for (u32 i=0; i<s->link_count; ++i) {
        if (s->links[i].from == (u16)from && s->links[i].to == (u16)to) return false;
    }
    s->links[s->link_count++] = (aether_path_link_t){(u16)from, (u16)to, cost};
    s->nodes[from].link_count++;
    return true;
}

int aetherpathfind_nearest_node(const aether_pathfind_state_t *s, aether_vec3_t position, f32 max_distance) {
    if (!s || s->node_count == 0) return -1;
    f32 best = max_distance > 0 ? max_distance : INFINITY;
    int result = -1;
    for (u32 i=0; i<s->node_count; ++i) {
        if (!s->nodes[i].enabled) continue;
        const f32 d = dist3(position, s->nodes[i].position);
        if (d <= best) { best = d; result = (int)i; }
    }
    return result;
}

u32 aetherpathfind_find(const aether_pathfind_state_t *s, u32 start_id, u32 goal_id,
                        u16 *out_path, u32 max_path) {
    if (!s || !s->enabled || !out_path || max_path == 0) return 0;
    const int start=node_index(s,start_id), goal=node_index(s,goal_id);
    if (start < 0 || goal < 0 || !s->nodes[start].enabled || !s->nodes[goal].enabled) return 0;
    if (start == goal) { out_path[0]=(u16)start_id; return 1; }

    f32 g[AETHER_PATH_MAX_NODES], f[AETHER_PATH_MAX_NODES];
    i16 parent[AETHER_PATH_MAX_NODES];
    bool open[AETHER_PATH_MAX_NODES], closed[AETHER_PATH_MAX_NODES];
    for (u32 i=0;i<s->node_count;++i) { g[i]=INFINITY; f[i]=INFINITY; parent[i]=-1; open[i]=false; closed[i]=false; }
    g[start]=0; f[start]=dist3(s->nodes[start].position,s->nodes[goal].position); open[start]=true;

    int current=-1;
    for (;;) {
        f32 best=INFINITY;
        for (u32 i=0;i<s->node_count;++i) if(open[i] && !closed[i] && f[i]<best) {best=f[i];current=(int)i;}
        if (current<0) return 0;
        if (current==goal) break;
        open[current]=false; closed[current]=true;
        for (u32 li=0; li<s->link_count; ++li) {
            if (s->links[li].from != (u16)current) continue;
            const int next=s->links[li].to;
            if(next<0 || (u32)next>=s->node_count || closed[next] || !s->nodes[next].enabled) continue;
            const f32 tentative=g[current]+s->links[li].cost;
            if(!open[next] || tentative<g[next]) {
                parent[next]=(i16)current;
                g[next]=tentative;
                f[next]=tentative+dist3(s->nodes[next].position,s->nodes[goal].position);
                open[next]=true;
            }
        }
    }

    u16 reverse[AETHER_PATH_MAX_RESULT];
    u32 count=0;
    for(int at=goal; at>=0 && count<AETHER_PATH_MAX_RESULT; at=parent[at]) {
        reverse[count++]=(u16)s->nodes[at].id;
        if(at==start) break;
    }
    if (reverse[count-1] != (u16)start_id) return 0;
    if (count > max_path) count=max_path;
    for(u32 i=0;i<count;++i) out_path[i]=reverse[count-1-i];
    return count;
}
