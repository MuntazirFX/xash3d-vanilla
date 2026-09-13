#include "AetherOsprey.h"
void aetherosprey_init(aether_monster_t *m,u32 id,aether_vec3_t p) { aether_monster_init(m,id,"monster_osprey",p,300.0f,220.0f); }
void aetherosprey_update(aether_monster_t *m,aether_vec3_t target,f32 dt) { aether_monster_update(m,target,dt); }
