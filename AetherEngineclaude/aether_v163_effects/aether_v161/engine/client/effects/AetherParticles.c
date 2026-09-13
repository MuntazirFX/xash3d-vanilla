#include "AetherParticles.h"
#include <string.h>
void aetherparticles_init(aetherparticles_state_t *s) { if (s) memset(s, 0, sizeof *s); }
bool aetherparticles_spawn(aetherparticles_state_t *s, aether_vec3_t pos, aether_vec3_t vel, f32 life, f32 gscale) {
    if (!s || s->count >= AETHER_PARTICLES_MAX) return false;
    aether_particle_t *p = &s->particles[s->count++];
    p->position = pos; p->velocity = vel; p->life = life > 0 ? life : 1.0f; p->gravity_scale = gscale;
    return true;
}
void aetherparticles_update(aetherparticles_state_t *s, f32 dt) {
    if (!s) return;
    u32 write = 0;
    for (u32 i = 0; i < s->count; i++) {
        s->particles[i].life -= dt;
        if (s->particles[i].life <= 0) continue;
        s->particles[i].velocity.z -= 300.0f * s->particles[i].gravity_scale * dt;
        s->particles[i].position.x += s->particles[i].velocity.x * dt;
        s->particles[i].position.y += s->particles[i].velocity.y * dt;
        s->particles[i].position.z += s->particles[i].velocity.z * dt;
        s->particles[write++] = s->particles[i];
    }
    s->count = write;
}
u32 aetherparticles_alive_count(const aetherparticles_state_t *s) { return s ? s->count : 0; }
