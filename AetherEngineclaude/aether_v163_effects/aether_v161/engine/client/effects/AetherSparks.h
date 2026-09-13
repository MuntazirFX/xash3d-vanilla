#ifndef AETHER_SPARKS_H
#define AETHER_SPARKS_H
#include "../../core/AetherCore.h"
#include "../../core/AetherMath.h"
#ifdef __cplusplus
extern "C" {
#endif
#define AETHER_SPARKS_MAX_BURST 12
typedef struct { aether_vec3_t position, velocity; f32 life; } aether_spark_t;
typedef struct aethersparks_state {
    aether_spark_t particles[AETHER_SPARKS_MAX_BURST];
    u32 count;
} aethersparks_state_t;
void aethersparks_init(aethersparks_state_t *s);
/* Spawns a short burst radiating from impact_normal (metal/rock surface hit). */
void aethersparks_burst(aethersparks_state_t *s, aether_vec3_t position, aether_vec3_t impact_normal);
void aethersparks_update(aethersparks_state_t *s, f32 dt);
#ifdef __cplusplus
}
#endif
#endif
