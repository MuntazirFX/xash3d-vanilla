#include "AetherSparks.h"
#include <string.h>
void aethersparks_init(aethersparks_state_t *s) { if (s) memset(s, 0, sizeof *s); }
void aethersparks_burst(aethersparks_state_t *s, aether_vec3_t pos, aether_vec3_t n) {
    if (!s) return;
    s->count = AETHER_SPARKS_MAX_BURST;
    for (u32 i = 0; i < AETHER_SPARKS_MAX_BURST; i++) {
        /* deterministic fan spread around the surface normal, cheap and reproducible */
        f32 spread = ((f32)i / AETHER_SPARKS_MAX_BURST) * 2.0f - 1.0f;
        s->particles[i].position = pos;
        s->particles[i].velocity.x = n.x * 150.0f + spread * 80.0f;
        s->particles[i].velocity.y = n.y * 150.0f + spread * 80.0f;
        s->particles[i].velocity.z = n.z * 150.0f + 60.0f;
        s->particles[i].life = 0.25f;
    }
}
void aethersparks_update(aethersparks_state_t *s, f32 dt) {
    if (!s) return;
    u32 write = 0;
    for (u32 i = 0; i < s->count; i++) {
        s->particles[i].life -= dt;
        if (s->particles[i].life <= 0) continue;
        s->particles[i].position.x += s->particles[i].velocity.x * dt;
        s->particles[i].position.y += s->particles[i].velocity.y * dt;
        s->particles[i].position.z += s->particles[i].velocity.z * dt;
        s->particles[i].velocity.z -= 400.0f * dt; /* gravity */
        s->particles[write++] = s->particles[i];
    }
    s->count = write;
}
