#include "AetherScientist.h"
void aetherscientist_init(aether_monster_t *m,u32 id,aether_vec3_t p) { aether_monster_init(m,id,"monster_scientist",p,20.0f,50.0f); }
void aetherscientist_update(aether_monster_t *m,aether_vec3_t target,f32 dt) { aether_monster_update(m,target,dt); }
