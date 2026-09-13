#include "AetherSplash.h"
#include <string.h>
static f32 clampf_(f32 v, f32 a, f32 b) { return v < a ? a : (v > b ? b : v); }
void aethersplash_init(aethersplash_state_t *s) { if (s) memset(s, 0, sizeof *s); }
void aethersplash_spawn(aethersplash_state_t *s, aether_vec3_t pos, f32 speed) {
    if (!s) return;
    s->position = pos;
    s->size = clampf_(speed * 0.05f, 4.0f, 64.0f); /* faster entry = bigger splash */
    s->life = 0.6f;
    s->active = true;
}
void aethersplash_update(aethersplash_state_t *s, f32 dt) {
    if (!s || !s->active) return;
    s->life -= dt;
    if (s->life <= 0) s->active = false;
}
