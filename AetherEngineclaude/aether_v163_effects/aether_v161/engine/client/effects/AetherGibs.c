#include "AetherGibs.h"
#include <string.h>
#include <math.h>
static f32 clampf_(f32 v, f32 a, f32 b) { return v < a ? a : (v > b ? b : v); }
void aethergibs_init(aethergibs_state_t *s) { if (s) memset(s, 0, sizeof *s); }
void aethergibs_spawn(aethergibs_state_t *s, aether_vec3_t pos, f32 scale) {
    if (!s) return;
    scale = clampf_(scale, 0.5f, 3.0f);
    u32 count = (u32)clampf_(4 * scale, 2, AETHER_GIBS_MAX);
    s->count = count;
    for (u32 i = 0; i < count; i++) {
        f32 ang = (f32)i / count * 6.2831853f;
        s->pieces[i].position = pos;
        s->pieces[i].velocity.x = (f32)cosf(ang) * 140.0f * scale;
        s->pieces[i].velocity.y = (f32)sinf(ang) * 140.0f * scale;
        s->pieces[i].velocity.z = 180.0f * scale;
        s->pieces[i].life = 4.0f;
    }
}
void aethergibs_update(aethergibs_state_t *s, f32 dt) {
    if (!s) return;
    u32 write = 0;
    for (u32 i = 0; i < s->count; i++) {
        s->pieces[i].life -= dt;
        if (s->pieces[i].life <= 0) continue;
        s->pieces[i].position.x += s->pieces[i].velocity.x * dt;
        s->pieces[i].position.y += s->pieces[i].velocity.y * dt;
        s->pieces[i].position.z += s->pieces[i].velocity.z * dt;
        s->pieces[i].velocity.z -= 450.0f * dt;
        s->pieces[write++] = s->pieces[i];
    }
    s->count = write;
}
