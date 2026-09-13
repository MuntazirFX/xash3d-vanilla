#ifndef AETHER_AI_H
#define AETHER_AI_H

#include "../../core/AetherCore.h"
#include "../../core/AetherMath.h"
#include "../monsters/AetherMonsterBase.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum aether_ai_state {
    AETHER_AI_IDLE = 0,
    AETHER_AI_ALERT,
    AETHER_AI_CHASE,
    AETHER_AI_ATTACK,
    AETHER_AI_DEAD
} aether_ai_state_t;

typedef struct aether_ai {
    bool enabled;
    aether_ai_state_t state;
    u32 target_id;
    f32 sight_range;
    f32 attack_range;
    f32 lose_target_range;
    f32 attack_cooldown;
    f32 think_interval;
    f32 think_timer;
    f32 attack_timer;
    aether_vec3_t last_seen_position;
    bool has_last_seen;
    u32 state_changes;
    u32 attacks;
} aether_ai_t;

void aether_ai_init(aether_ai_t *ai);
void aether_ai_reset(aether_ai_t *ai);
void aether_ai_set_ranges(aether_ai_t *ai, f32 sight, f32 attack, f32 lose);
void aether_ai_update(aether_ai_t *ai, aether_monster_t *monster,
                      u32 target_id, aether_vec3_t target_position, f32 dt);
bool aether_ai_can_attack(const aether_ai_t *ai);
bool aether_ai_take_attack(aether_ai_t *ai);
aether_ai_state_t aether_ai_state(const aether_ai_t *ai);

/* Compatibility wrappers retained for the original subsystem API. */
typedef aether_ai_t aetherai_state_t;
void aetherai_init(aetherai_state_t *s);
void aetherai_update(aetherai_state_t *s, f32 dt);
void aetherai_reset(aetherai_state_t *s);
void aetherai_event(aetherai_state_t *s);

#ifdef __cplusplus
}
#endif
#endif
