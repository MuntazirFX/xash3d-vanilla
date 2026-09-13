#include "AetherApache.h"
void aetherapache_init(aether_monster_t *m,u32 id,aether_vec3_t p) { aether_monster_init(m,id,"monster_apache",p,200.0f,250.0f); }
void aetherapache_update(aether_monster_t *m,aether_vec3_t target,f32 dt) { aether_monster_update(m,target,dt); }
