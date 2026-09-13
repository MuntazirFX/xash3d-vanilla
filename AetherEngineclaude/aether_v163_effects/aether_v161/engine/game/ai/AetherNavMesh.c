#include "AetherNavMesh.h"
#include <string.h>

void aethernavmesh_init(aethernavmesh_state_t *s) {
    if (!s) return;
    memset(s,0,sizeof*s);
    s->enabled=true;
    s->node_radius=32.0f;
    aetherpathfind_init(&s->graph);
    aether_str_copy(s->text,sizeof s->text,"navigation graph ready");
}
void aethernavmesh_update(aethernavmesh_state_t *s,f32 dt){if(!s||!s->enabled)return;s->value += dt;aetherpathfind_update(&s->graph,dt);}
void aethernavmesh_reset(aethernavmesh_state_t *s){if(!s)return;const bool e=s->enabled;aethernavmesh_init(s);s->enabled=e;}
void aethernavmesh_event(aethernavmesh_state_t *s){if(s){s->events++;aetherpathfind_event(&s->graph);}}
int aethernavmesh_add_node(aethernavmesh_state_t*s,u32 id,aether_vec3_t p){int r=aetherpathfind_add_node(&s->graph,id,p);if(r>=0)s->generated_nodes=s->graph.node_count;return r;}
bool aethernavmesh_connect(aethernavmesh_state_t*s,u32 a,u32 b){
    if(!s) return false;
    const int ai=aetherpathfind_add_link(&s->graph,a,b,0);
    const int bi=aetherpathfind_add_link(&s->graph,b,a,0);
    return ai>=0 && bi>=0;
}
int aethernavmesh_nearest(const aethernavmesh_state_t*s,aether_vec3_t p,f32 max_distance){return s?aetherpathfind_nearest_node(&s->graph,p,max_distance):-1;}
u32 aethernavmesh_route(const aethernavmesh_state_t*s,u32 a,u32 b,u16*out,u32 max_out){return s?aetherpathfind_find(&s->graph,a,b,out,max_out):0;}
