#include "AetherBarnacle.h"
void aetherbarnacle_init(aether_monster_t *m,u32 id,aether_vec3_t p) { aether_monster_init(m,id,"monster_barnacle",p,35.0f,0.0f); }
void aetherbarnacle_update(aether_monster_t *m,aether_vec3_t target,f32 dt) { aether_monster_update(m,target,dt); }
