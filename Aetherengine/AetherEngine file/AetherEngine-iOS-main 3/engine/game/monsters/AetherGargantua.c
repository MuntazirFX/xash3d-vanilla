#include "AetherGargantua.h"
void aethergargantua_init(aether_monster_t *m,u32 id,aether_vec3_t p) { aether_monster_init(m,id,"monster_gargantua",p,800.0f,50.0f); }
void aethergargantua_update(aether_monster_t *m,aether_vec3_t target,f32 dt) { aether_monster_update(m,target,dt); }
