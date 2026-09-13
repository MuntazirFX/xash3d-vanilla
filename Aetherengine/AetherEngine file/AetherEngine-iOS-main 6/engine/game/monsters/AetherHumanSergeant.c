#include "AetherHumanSergeant.h"
void aetherhumansergeant_init(aether_monster_t *m,u32 id,aether_vec3_t p) { aether_monster_init(m,id,"monster_human_sergeant",p,60.0f,90.0f); }
void aetherhumansergeant_update(aether_monster_t *m,aether_vec3_t target,f32 dt) { aether_monster_update(m,target,dt); }
