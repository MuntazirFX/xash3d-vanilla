#ifndef AETHER_NPC_COMBAT_H
#define AETHER_NPC_COMBAT_H
#include "AetherNPCProfile.h"
#ifdef __cplusplus
extern "C" {
#endif
f32 aether_npc_attack_damage(const aether_monster_t *monster);
void aether_npc_mark_attack(aether_monster_t *monster);
bool aether_npc_is_hostile(const aether_monster_t *monster);
#ifdef __cplusplus
}
#endif
#endif
