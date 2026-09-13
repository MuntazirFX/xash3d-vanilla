#ifndef AETHER_COMBAT_FX_H
#define AETHER_COMBAT_FX_H

#include "../../core/AetherCore.h"
#include "../../core/AetherMath.h"
#include "../../game/AetherCombat.h"

#ifdef __cplusplus
extern "C" {
#endif

#define AETHER_FX_MAX_EVENTS 64

typedef enum aether_fx_type {
    AETHER_FX_NONE = 0,
    AETHER_FX_MUZZLE,
    AETHER_FX_TRACER,
    AETHER_FX_IMPACT
} aether_fx_type_t;

typedef struct aether_fx_event {
    aether_fx_type_t type;
    aether_weapon_id_t weapon;
    aether_vec3_t origin;
    aether_vec3_t direction;
    aether_vec3_t end;
    f32 age;
    f32 lifetime;
    f32 intensity;
    bool active;
} aether_fx_event_t;

typedef struct aether_combat_fx {
    aether_fx_event_t events[AETHER_FX_MAX_EVENTS];
    u32 count;
    u64 emitted;
} aether_combat_fx_t;

void aether_combat_fx_init(aether_combat_fx_t *fx);
void aether_combat_fx_update(aether_combat_fx_t *fx, f32 dt);
void aether_combat_fx_reset(aether_combat_fx_t *fx);
void aether_combat_fx_consume(aether_combat_fx_t *fx, const aether_combat_event_t *event);
const aether_fx_event_t *aether_combat_fx_at(const aether_combat_fx_t *fx, u32 index);
u32 aether_combat_fx_count(const aether_combat_fx_t *fx);
u64 aether_combat_fx_emitted(const aether_combat_fx_t *fx);

#ifdef __cplusplus
}
#endif
#endif
