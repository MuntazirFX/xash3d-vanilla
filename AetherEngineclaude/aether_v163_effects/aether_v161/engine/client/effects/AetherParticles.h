#ifndef AETHER_PARTICLES_H
#define AETHER_PARTICLES_H
#include "../../core/AetherCore.h"
#include "../../core/AetherMath.h"
#ifdef __cplusplus
extern "C" {
#endif
#define AETHER_PARTICLES_MAX 48
typedef struct { aether_vec3_t position, velocity; f32 life, gravity_scale; } aether_particle_t;
typedef struct aetherparticles_state {
    aether_particle_t particles[AETHER_PARTICLES_MAX];
    u32 count;
} aetherparticles_state_t;
void aetherparticles_init(aetherparticles_state_t *s);
/* Returns false if the pool is full (spawn skipped) so callers can react. */
bool aetherparticles_spawn(aetherparticles_state_t *s, aether_vec3_t position,
                            aether_vec3_t velocity, f32 life, f32 gravity_scale);
void aetherparticles_update(aetherparticles_state_t *s, f32 dt);
u32  aetherparticles_alive_count(const aetherparticles_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
