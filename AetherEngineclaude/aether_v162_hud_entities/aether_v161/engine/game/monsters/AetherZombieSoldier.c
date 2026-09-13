#include "AetherZombieSoldier.h"
void aetherzombiesoldier_init(aether_monster_t *m,u32 id,aether_vec3_t p) { aether_monster_init(m,id,"monster_zombie_soldier",p,60.0f,42.0f); }
void aetherzombiesoldier_update(aether_monster_t *m,aether_vec3_t target,f32 dt) { aether_monster_update(m,target,dt); }
