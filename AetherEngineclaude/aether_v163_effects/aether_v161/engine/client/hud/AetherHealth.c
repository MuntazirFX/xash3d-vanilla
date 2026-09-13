#include "AetherHealth.h"
#include <string.h>
#include <math.h>
void aetherhealth_init(aetherhealth_state_t *s) { if (s) memset(s, 0, sizeof *s); }
void aetherhealth_set(aetherhealth_state_t *s, f32 hp, f32 max_hp) {
    if (!s) return;
    s->display_value = (i32)(hp + 0.5f);
    f32 ratio = max_hp > 0 ? hp / max_hp : 0;
    s->critical   = ratio <= 0.10f;
    s->low_health = ratio <= 0.20f;
}
void aetherhealth_update(aetherhealth_state_t *s, f32 dt) {
    if (!s) return;
    f32 speed = s->critical ? 6.0f : 3.0f;
    s->pulse_phase += dt * speed;
    if (s->pulse_phase > 6.2831853f) s->pulse_phase -= 6.2831853f;
}
f32 aetherhealth_pulse_alpha(const aetherhealth_state_t *s) {
    if (!s || !s->low_health) return 1.0f;
    return 0.65f + 0.35f * sinf(s->pulse_phase);
}
