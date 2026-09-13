#ifndef AETHER_ZOMBIE_H
#define AETHER_ZOMBIE_H
#include "AetherMonsterBase.h"
#ifdef __cplusplus
extern "C" {
#endif

void aetherzombie_init(aether_monster_t *m, u32 id, aether_vec3_t p);
void aetherzombie_update(aether_monster_t *m, aether_vec3_t target, f32 dt);
bool aetherzombie_can_attack(const aether_monster_t *m);
/* Slow wind-up melee swing — high damage, long cooldown, short range. */
f32  aetherzombie_attack(aether_monster_t *m);

#ifdef __cplusplus
}
#endif
#endif
