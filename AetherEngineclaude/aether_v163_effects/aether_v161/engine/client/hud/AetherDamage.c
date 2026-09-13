#include "AetherDamage.h"
#include <string.h>
static f32 clampf_(f32 v, f32 a, f32 b) { return v < a ? a : (v > b ? b : v); }
void aetherdamage_init(aetherdamage_state_t *s) { if (s) memset(s, 0, sizeof *s); }
void aetherdamage_register(aetherdamage_state_t *s, f32 angle_deg, f32 amount) {
    if (!s || amount <= 0) return;
    s->flash = clampf_(s->flash + amount * 0.01f, 0, 1);
    u32 slot = s->count < AETHER_DAMAGE_MAX_INDICATORS ? s->count++ : 0;
    s->indicators[slot].angle_deg = angle_deg;
    s->indicators[slot].life = 1.5f; /* on screen for 1.5s */
}
void aetherdamage_update(aetherdamage_state_t *s, f32 dt) {
    if (!s) return;
    s->flash = clampf_(s->flash - dt * 1.5f, 0, 1);
    u32 write = 0;
    for (u32 i = 0; i < s->count; i++) {
        s->indicators[i].life -= dt;
        if (s->indicators[i].life > 0) s->indicators[write++] = s->indicators[i];
    }
    s->count = write;
}
