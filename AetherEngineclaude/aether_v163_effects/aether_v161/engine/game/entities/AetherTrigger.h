/* AetherTrigger.h — trigger volumes: multiple / once / hurt / push (real implementation).
 * AetherEngine-iOS · Clean-room.
 */
#ifndef AETHER_AETHERTRIGGER_H
#define AETHER_AETHERTRIGGER_H
#include "../../core/AetherCore.h"
#include "../../core/AetherMath.h"
#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    AETHER_TRIGGER_MULTIPLE = 0, /* can fire repeatedly, respects re-trigger delay */
    AETHER_TRIGGER_ONCE,         /* fires exactly once then disables itself */
    AETHER_TRIGGER_HURT,         /* deals damage_per_sec to anything inside every tick */
    AETHER_TRIGGER_PUSH          /* applies push_velocity to anything inside every tick */
} aether_trigger_kind_t;

typedef struct aethertrigger_state {
    bool   enabled;
    aether_trigger_kind_t kind;
    aether_vec3_t mins, maxs;   /* AABB in world space */
    f32    delay;               /* re-trigger cooldown for MULTIPLE */
    f32    delay_timer;
    f32    damage_per_sec;      /* used by HURT */
    aether_vec3_t push_velocity;/* used by PUSH */
    bool   fired_once;          /* used by ONCE */
    u32    events;
    char   target[32];          /* entity name to fire (door/button/etc) */
} aethertrigger_state_t;

void aethertrigger_init(aethertrigger_state_t *s, aether_trigger_kind_t kind,
                         aether_vec3_t mins, aether_vec3_t maxs);
void aethertrigger_set_hurt(aethertrigger_state_t *s, f32 damage_per_sec);
void aethertrigger_set_push(aethertrigger_state_t *s, aether_vec3_t velocity);
void aethertrigger_set_delay(aethertrigger_state_t *s, f32 delay);
void aethertrigger_reset(aethertrigger_state_t *s);

bool aethertrigger_contains(const aethertrigger_state_t *s, aether_vec3_t point);

/* Call every frame with the toucher's position. Returns true the tick it actually fires
 * (i.e. target should be activated / damage applied this frame). */
bool aethertrigger_update(aethertrigger_state_t *s, aether_vec3_t toucher_pos, f32 dt, f32 *out_damage);

#ifdef __cplusplus
}
#endif
#endif
