#include "AetherCombatFX.h"
#include <string.h>
#include <math.h>

static void clear_slot(aether_fx_event_t *e) { if (e) memset(e, 0, sizeof *e); }

void aether_combat_fx_init(aether_combat_fx_t *fx) {
    if (!fx) return;
    memset(fx, 0, sizeof *fx);
}

void aether_combat_fx_reset(aether_combat_fx_t *fx) { aether_combat_fx_init(fx); }

static aether_fx_event_t *alloc_event(aether_combat_fx_t *fx) {
    if (!fx) return NULL;
    for (u32 i = 0; i < AETHER_FX_MAX_EVENTS; ++i) {
        if (!fx->events[i].active) return &fx->events[i];
    }
    /* Recycle the oldest event when the fixed pool is full. */
    u32 oldest = 0;
    f32 age = -1.0f;
    for (u32 i = 0; i < AETHER_FX_MAX_EVENTS; ++i) {
        if (fx->events[i].age > age) { age = fx->events[i].age; oldest = i; }
    }
    return &fx->events[oldest];
}

static void emit(aether_combat_fx_t *fx, aether_fx_type_t type,
                 aether_weapon_id_t weapon, aether_vec3_t origin,
                 aether_vec3_t direction, aether_vec3_t end,
                 f32 lifetime, f32 intensity) {
    aether_fx_event_t *e = alloc_event(fx);
    if (!e) return;
    clear_slot(e);
    e->type = type;
    e->weapon = weapon;
    e->origin = origin;
    e->direction = direction;
    e->end = end;
    e->lifetime = lifetime;
    e->intensity = intensity;
    e->active = true;
    fx->emitted++;
    if (fx->count < AETHER_FX_MAX_EVENTS) fx->count++;
}

void aether_combat_fx_consume(aether_combat_fx_t *fx, const aether_combat_event_t *event) {
    if (!fx || !event) return;
    switch (event->type) {
        case AETHER_COMBAT_FIRED: {
            const f32 range = 48.0f;
            aether_vec3_t end = {
                event->origin.x + event->direction.x * range,
                event->origin.y + event->direction.y * range,
                event->origin.z + event->direction.z * range
            };
            emit(fx, AETHER_FX_MUZZLE, event->weapon, event->origin, event->direction,
                 event->origin, 0.075f, 1.0f);
            if (event->weapon != AETHER_WEAPON_CROWBAR)
                emit(fx, AETHER_FX_TRACER, event->weapon, event->origin, event->direction,
                     end, 0.055f, 0.8f);
            break;
        }
        case AETHER_COMBAT_HIT:
        case AETHER_COMBAT_KILLED:
            emit(fx, AETHER_FX_IMPACT, event->weapon, event->origin, event->direction,
                 event->origin, 0.12f, event->type == AETHER_COMBAT_KILLED ? 1.25f : 1.0f);
            break;
        default:
            break;
    }
}

void aether_combat_fx_update(aether_combat_fx_t *fx, f32 dt) {
    if (!fx) return;
    if (dt < 0.0f) dt = 0.0f;
    for (u32 i = 0; i < AETHER_FX_MAX_EVENTS; ++i) {
        aether_fx_event_t *e = &fx->events[i];
        if (!e->active) continue;
        e->age += dt;
        if (e->age >= e->lifetime) {
            clear_slot(e);
            if (fx->count > 0) fx->count--;
        }
    }
}

const aether_fx_event_t *aether_combat_fx_at(const aether_combat_fx_t *fx, u32 index) {
    if (!fx || index >= AETHER_FX_MAX_EVENTS || !fx->events[index].active) return NULL;
    return &fx->events[index];
}

u32 aether_combat_fx_count(const aether_combat_fx_t *fx) { return fx ? fx->count : 0; }
u64 aether_combat_fx_emitted(const aether_combat_fx_t *fx) { return fx ? fx->emitted : 0; }
