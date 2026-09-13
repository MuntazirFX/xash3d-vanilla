#ifndef AETHER_COMBAT_H
#define AETHER_COMBAT_H

#include "../core/AetherCore.h"
#include "../core/AetherMath.h"
#include "player/AetherPlayerDamage.h"
#include "weapons/AetherWeapon.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum aether_combat_event_type {
    AETHER_COMBAT_NONE = 0,
    AETHER_COMBAT_FIRED,
    AETHER_COMBAT_EMPTY,
    AETHER_COMBAT_HIT,
    AETHER_COMBAT_KILLED,
    AETHER_COMBAT_RELOADED,
    AETHER_COMBAT_SWITCHED,
    AETHER_COMBAT_PLAYER_HIT,
    AETHER_COMBAT_PLAYER_DIED
} aether_combat_event_type_t;

typedef struct aether_combat_event {
    aether_combat_event_type_t type;
    aether_weapon_id_t weapon;
    u32 target_id;
    f32 damage;
    aether_vec3_t origin;
    aether_vec3_t direction;
    u64 sequence;
} aether_combat_event_t;

void aether_combat_event_clear(aether_combat_event_t *event);
void aether_combat_event_make(aether_combat_event_t *event,
                              aether_combat_event_type_t type,
                              aether_weapon_id_t weapon,
                              u32 target_id,
                              f32 damage,
                              aether_vec3_t origin,
                              aether_vec3_t direction,
                              u64 sequence);

#ifdef __cplusplus
}
#endif
#endif
