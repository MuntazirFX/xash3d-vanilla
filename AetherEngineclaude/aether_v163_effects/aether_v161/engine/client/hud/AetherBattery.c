#include "AetherBattery.h"
#include <string.h>
static f32 clampf_(f32 v, f32 a, f32 b) { return v < a ? a : (v > b ? b : v); }
void aetherbattery_init(aetherbattery_state_t *s) {
    if (!s) return;
    memset(s, 0, sizeof *s);
    s->max_charge = 100.0f;
    s->charge = 100.0f;
}
void aetherbattery_set_flashlight(aetherbattery_state_t *s, bool on) {
    if (!s) return;
    /* can't turn on flashlight with an empty battery */
    s->flashlight_on = on && s->charge > 0;
}
void aetherbattery_update(aetherbattery_state_t *s, f32 dt) {
    if (!s) return;
    if (s->flashlight_on) {
        s->charge = clampf_(s->charge - dt * 5.0f, 0, s->max_charge); /* drains in 20s */
        if (s->charge <= 0) s->flashlight_on = false;
    }
    s->low = s->charge <= s->max_charge * 0.20f;
}
void aetherbattery_recharge(aetherbattery_state_t *s, f32 amount) {
    if (!s || amount <= 0) return;
    s->charge = clampf_(s->charge + amount, 0, s->max_charge);
    s->low = s->charge <= s->max_charge * 0.20f;
}
