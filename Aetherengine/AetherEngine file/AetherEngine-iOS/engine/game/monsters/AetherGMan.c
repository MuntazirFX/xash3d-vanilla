#include "AetherGMan.h"
void aethergman_init(aether_monster_t *m,u32 id,aether_vec3_t p) { aether_monster_init(m,id,"monster_gman",p,100.0f,40.0f); }
void aethergman_update(aether_monster_t *m,aether_vec3_t target,f32 dt) { aether_monster_update(m,target,dt); }
