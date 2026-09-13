#include "AetherBlood.h"
#include <string.h>
static f32 clampf_(f32 v, f32 a, f32 b) { return v < a ? a : (v > b ? b : v); }
void aetherblood_init(aetherblood_state_t *s) { if (s) memset(s, 0, sizeof *s); }
void aetherblood_spawn(aetherblood_state_t *s, aether_vec3_t pos, f32 damage) {
    if (!s || damage <= 0) return;
    u32 slot = s->count < AETHER_BLOOD_MAX ? s->count++ : 0; /* recycle oldest at slot 0 */
    s->decals[slot].position = pos;
    s->decals[slot].size = clampf_(damage * 0.3f, 4.0f, 40.0f);
    s->decals[slot].life = 12.0f; /* decals persist longer than particle FX */
}
void aetherblood_update(aetherblood_state_t *s, f32 dt) {
    if (!s) return;
    u32 write = 0;
    for (u32 i = 0; i < s->count; i++) {
        s->decals[i].life -= dt;
        if (s->decals[i].life > 0) s->decals[write++] = s->decals[i];
    }
    s->count = write;
}
