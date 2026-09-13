#include "AetherHeadcrab.h"
void aether_headcrab_init(aether_monster_t*m,u32 id,aether_vec3_t p){aether_monster_init(m,id,"monster_headcrab",p,20.0f,72.0f);m->attack_range=48;m->perception_range=768;}
bool aether_headcrab_can_attack(const aether_monster_t*m){return m&&m->alive&&m->state==AETHER_MONSTER_COMBAT&&m->attack_cooldown<=0;}
f32 aether_headcrab_attack(aether_monster_t*m){if(!aether_headcrab_can_attack(m))return 0;m->attack_cooldown=1.2f;return 10.0f;}
