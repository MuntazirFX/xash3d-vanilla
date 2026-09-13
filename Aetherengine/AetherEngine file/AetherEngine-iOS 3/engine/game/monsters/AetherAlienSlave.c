#include "AetherAlienSlave.h"
void aetheralienslave_init(aether_monster_t *m,u32 id,aether_vec3_t p) { aether_monster_init(m,id,"monster_alien_slave",p,80.0f,60.0f); }
void aetheralienslave_update(aether_monster_t *m,aether_vec3_t target,f32 dt) { aether_monster_update(m,target,dt); }
