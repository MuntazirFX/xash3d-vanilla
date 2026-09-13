#include "AetherTracer.h"
#include <string.h>
#include <math.h>
static f32 clampf_(f32 v, f32 a, f32 b) { return v < a ? a : (v > b ? b : v); }
void aethertracer_init(aethertracer_state_t *s) { if (s) memset(s, 0, sizeof *s); }
void aethertracer_fire(aethertracer_state_t *s, aether_vec3_t start, aether_vec3_t end, f32 speed) {
    if (!s) return;
    s->start = start; s->end = end;
    s->speed = speed > 0 ? speed : 4000.0f; /* fast, but visible unlike true hitscan */
    s->progress = 0;
    s->active = true;
}
void aethertracer_update(aethertracer_state_t *s, f32 dt) {
    if (!s || !s->active) return;
    f32 dx = s->end.x - s->start.x, dy = s->end.y - s->start.y, dz = s->end.z - s->start.z;
    f32 dist = sqrtf(dx*dx + dy*dy + dz*dz);
    if (dist <= 0.0001f) { s->active = false; return; }
    s->progress += (s->speed * dt) / dist;
    if (s->progress >= 1.0f) { s->progress = 1.0f; s->active = false; }
}
aether_vec3_t aethertracer_current_position(const aethertracer_state_t *s) {
    aether_vec3_t r = {0,0,0};
    if (!s) return r;
    f32 t = clampf_(s->progress, 0, 1);
    r.x = s->start.x + (s->end.x - s->start.x) * t;
    r.y = s->start.y + (s->end.y - s->start.y) * t;
    r.z = s->start.z + (s->end.z - s->start.z) * t;
    return r;
}
