#include "AetherTurret.h"
void aetherturret_init(aether_monster_t *m,u32 id,aether_vec3_t p) { aether_monster_init(m,id,"monster_turret",p,150.0f,0.0f); }
void aetherturret_update(aether_monster_t *m,aether_vec3_t target,f32 dt) { aether_monster_update(m,target,dt); }
