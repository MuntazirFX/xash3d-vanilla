#include "AetherLeech.h"
void aetherleech_init(aether_monster_t *m,u32 id,aether_vec3_t p) { aether_monster_init(m,id,"monster_leech",p,15.0f,30.0f); }
void aetherleech_update(aether_monster_t *m,aether_vec3_t target,f32 dt) { aether_monster_update(m,target,dt); }
