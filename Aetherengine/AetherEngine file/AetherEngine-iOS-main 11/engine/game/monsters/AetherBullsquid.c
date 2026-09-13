#include "AetherBullsquid.h"
void aetherbullsquid_init(aether_monster_t *m,u32 id,aether_vec3_t p) { aether_monster_init(m,id,"monster_bullsquid",p,80.0f,70.0f); }
void aetherbullsquid_update(aether_monster_t *m,aether_vec3_t target,f32 dt) { aether_monster_update(m,target,dt); }
