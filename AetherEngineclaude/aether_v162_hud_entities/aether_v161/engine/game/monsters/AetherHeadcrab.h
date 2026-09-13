#ifndef AETHER_HEADCRAB_H
#define AETHER_HEADCRAB_H
#include "AetherMonsterBase.h"
void aether_headcrab_init(aether_monster_t*m,u32 id,aether_vec3_t pos);
bool aether_headcrab_can_attack(const aether_monster_t*m);
f32 aether_headcrab_attack(aether_monster_t*m);
#endif
