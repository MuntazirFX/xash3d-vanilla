#include "AetherAlienController.h"
void aetheraliencontroller_init(aether_monster_t *m,u32 id,aether_vec3_t p) { aether_monster_init(m,id,"monster_alien_controller",p,120.0f,55.0f); }
void aetheraliencontroller_update(aether_monster_t *m,aether_vec3_t target,f32 dt) { aether_monster_update(m,target,dt); }
