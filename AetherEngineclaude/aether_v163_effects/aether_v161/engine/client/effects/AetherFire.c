#include "AetherFire.h"
#include <string.h>
#include <math.h>
void aetherfire_init(aetherfire_state_t *s) { if (s) memset(s, 0, sizeof *s); }
void aetherfire_ignite(aetherfire_state_t *s, aether_vec3_t pos, f32 radius, f32 duration) {
    if (!s) return;
    s->position = pos;
    s->radius = radius > 0 ? radius : 48.0f;
    s->damage_per_sec = 8.0f;
    s->duration = duration > 0 ? duration : 5.0f;
    s->age = 0;
    s->active = true;
}
void aetherfire_update(aetherfire_state_t *s, f32 dt) {
    if (!s || !s->active) return;
    s->age += dt;
    if (s->age >= s->duration) s->active = false;
}
bool aetherfire_burns(const aetherfire_state_t *s, aether_vec3_t p) {
    if (!s || !s->active) return false;
    f32 dx = p.x - s->position.x, dy = p.y - s->position.y, dz = p.z - s->position.z;
    return sqrtf(dx*dx + dy*dy + dz*dz) <= s->radius;
}
