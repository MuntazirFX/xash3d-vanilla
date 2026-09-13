#include "AetherExplosionFX.h"
#include <string.h>
static f32 clampf_(f32 v, f32 a, f32 b) { return v < a ? a : (v > b ? b : v); }
void aetherexplosionfx_init(aetherexplosionfx_state_t *s) { if (s) memset(s, 0, sizeof *s); }
void aetherexplosionfx_spawn(aetherexplosionfx_state_t *s, aether_vec3_t pos, f32 radius) {
    if (!s) return;
    s->position = pos;
    s->radius = radius > 0 ? radius : 128.0f;
    s->age = 0;
    s->duration = 0.5f;
    s->active = true;
}
void aetherexplosionfx_update(aetherexplosionfx_state_t *s, f32 dt) {
    if (!s || !s->active) return;
    s->age += dt;
    if (s->age >= s->duration) s->active = false;
}
f32 aetherexplosionfx_scale(const aetherexplosionfx_state_t *s) {
    if (!s || !s->active) return 0;
    f32 t = clampf_(s->age / s->duration, 0, 1);
    /* fast expand, then fade: peak at t=0.3 */
    return t < 0.3f ? (t / 0.3f) : (1.0f - (t - 0.3f) / 0.7f);
}
f32 aetherexplosionfx_shake_at(const aetherexplosionfx_state_t *s, f32 dist) {
    if (!s || !s->active || dist >= s->radius * 4.0f) return 0;
    f32 falloff = clampf_(1.0f - dist / (s->radius * 4.0f), 0, 1);
    return falloff * aetherexplosionfx_scale(s);
}
