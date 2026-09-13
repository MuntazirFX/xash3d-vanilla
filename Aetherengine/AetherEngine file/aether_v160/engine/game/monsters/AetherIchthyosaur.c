#include "AetherIchthyosaur.h"
void aetherichthyosaur_init(aether_monster_t *m,u32 id,aether_vec3_t p) { aether_monster_init(m,id,"monster_ichthyosaur",p,200.0f,100.0f); }
void aetherichthyosaur_update(aether_monster_t *m,aether_vec3_t target,f32 dt) { aether_monster_update(m,target,dt); }
