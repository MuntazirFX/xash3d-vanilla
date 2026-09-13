#include "AetherHumanGrunt.h"
void aetherhumangrunt_init(aether_monster_t *m,u32 id,aether_vec3_t p) { aether_monster_init(m,id,"monster_human_grunt",p,50.0f,80.0f); }
void aetherhumangrunt_update(aether_monster_t *m,aether_vec3_t target,f32 dt) { aether_monster_update(m,target,dt); }
