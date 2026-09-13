#include "AetherZombieGonome.h"
void aetherzombiegonome_init(aether_monster_t *m,u32 id,aether_vec3_t p) { aether_monster_init(m,id,"monster_zombie_gonome",p,100.0f,55.0f); }
void aetherzombiegonome_update(aether_monster_t *m,aether_vec3_t target,f32 dt) { aether_monster_update(m,target,dt); }
