#include "AetherTrigger.h"
#include <string.h>

static f32 maxf_(f32 a, f32 b) { return a > b ? a : b; }

void aethertrigger_init(aethertrigger_state_t *s, aether_trigger_kind_t kind,
                         aether_vec3_t mins, aether_vec3_t maxs) {
    if (!s) return;
    memset(s, 0, sizeof *s);
    s->enabled = true;
    s->kind = kind;
    s->mins = mins;
    s->maxs = maxs;
    s->delay = 0.2f; /* default GoldSrc-style small re-trigger guard */
}

void aethertrigger_set_hurt(aethertrigger_state_t *s, f32 dps) { if (s) s->damage_per_sec = dps; }
void aethertrigger_set_push(aethertrigger_state_t *s, aether_vec3_t v) { if (s) s->push_velocity = v; }
void aethertrigger_set_delay(aethertrigger_state_t *s, f32 d) { if (s) s->delay = d; }

void aethertrigger_reset(aethertrigger_state_t *s) {
    if (!s) return;
    s->delay_timer = 0;
    s->fired_once = false;
}

bool aethertrigger_contains(const aethertrigger_state_t *s, aether_vec3_t p) {
    if (!s) return false;
    return p.x >= s->mins.x && p.x <= s->maxs.x &&
           p.y >= s->mins.y && p.y <= s->maxs.y &&
           p.z >= s->mins.z && p.z <= s->maxs.z;
}

bool aethertrigger_update(aethertrigger_state_t *s, aether_vec3_t pos, f32 dt, f32 *out_damage) {
    if (out_damage) *out_damage = 0;
    if (!s || !s->enabled) return false;
    if (s->kind == AETHER_TRIGGER_ONCE && s->fired_once) return false;

    s->delay_timer = maxf_(0.0f, s->delay_timer - dt);
    if (!aethertrigger_contains(s, pos)) return false;

    switch (s->kind) {
        case AETHER_TRIGGER_HURT:
            if (out_damage) *out_damage = s->damage_per_sec * dt;
            s->events++;
            return true;
        case AETHER_TRIGGER_PUSH:
            s->events++;
            return true; /* caller applies push_velocity to the toucher */
        case AETHER_TRIGGER_ONCE:
            s->fired_once = true;
            s->enabled = false; /* single-use, then dormant */
            s->events++;
            return true;
        case AETHER_TRIGGER_MULTIPLE:
        default:
            if (s->delay_timer > 0) return false;
            s->delay_timer = s->delay;
            s->events++;
            return true;
    }
}
