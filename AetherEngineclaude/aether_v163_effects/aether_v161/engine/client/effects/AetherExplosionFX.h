#ifndef AETHER_EXPLOSIONFX_H
#define AETHER_EXPLOSIONFX_H
#include "../../core/AetherCore.h"
#include "../../core/AetherMath.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherexplosionfx_state {
    aether_vec3_t position;
    f32 radius;          /* visual max radius reached */
    f32 age, duration;    /* grows from 0 to radius over duration, then fades */
    bool active;
} aetherexplosionfx_state_t;
void aetherexplosionfx_init(aetherexplosionfx_state_t *s);
void aetherexplosionfx_spawn(aetherexplosionfx_state_t *s, aether_vec3_t position, f32 radius);
void aetherexplosionfx_update(aetherexplosionfx_state_t *s, f32 dt);
/* 0..1 visual scale of the fireball right now (for renderer). */
f32  aetherexplosionfx_scale(const aetherexplosionfx_state_t *s);
/* Screen shake magnitude for a viewer at the given distance from the blast. */
f32  aetherexplosionfx_shake_at(const aetherexplosionfx_state_t *s, f32 viewer_distance);
#ifdef __cplusplus
}
#endif
#endif
