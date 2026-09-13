#include "AetherHoundeye.h"
void aetherhoundeye_init(aether_monster_t *m,u32 id,aether_vec3_t p) { aether_monster_init(m,id,"monster_houndeye",p,60.0f,70.0f); }
void aetherhoundeye_update(aether_monster_t *m,aether_vec3_t target,f32 dt) { aether_monster_update(m,target,dt); }
