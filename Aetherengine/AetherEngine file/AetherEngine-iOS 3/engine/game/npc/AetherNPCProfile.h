#ifndef AETHER_NPC_PROFILE_H
#define AETHER_NPC_PROFILE_H

#include "../monsters/AetherMonsterBase.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum aether_npc_attack_type {
    AETHER_NPC_ATTACK_NONE = 0,
    AETHER_NPC_ATTACK_MELEE,
    AETHER_NPC_ATTACK_RANGED
} aether_npc_attack_type_t;

typedef struct aether_npc_profile {
    const char *classname;
    f32 max_health;
    f32 speed;
    f32 perception_range;
    f32 attack_range;
    f32 attack_damage;
    f32 attack_cooldown;
    f32 attack_windup;
    aether_npc_attack_type_t attack_type;
    bool friendly;
} aether_npc_profile_t;

const aether_npc_profile_t *aether_npc_profile_for_classname(const char *classname);
void aether_npc_spawn(aether_monster_t *monster, u32 id, const char *classname, aether_vec3_t position);
bool aether_npc_can_attack(const aether_monster_t *monster, f32 time_since_attack);

#ifdef __cplusplus
}
#endif
#endif
