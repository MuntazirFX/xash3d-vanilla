#ifndef AETHER_TRACER_H
#define AETHER_TRACER_H
#include "../../core/AetherCore.h"
#include "../../core/AetherMath.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethertracer_state {
    aether_vec3_t start, end;
    f32 speed;      /* units/sec the visual trail travels, not the actual hitscan (instant) */
    f32 progress;    /* 0..1 along the path */
    bool active;
} aethertracer_state_t;
void aethertracer_init(aethertracer_state_t *s);
void aethertracer_fire(aethertracer_state_t *s, aether_vec3_t start, aether_vec3_t end, f32 speed);
void aethertracer_update(aethertracer_state_t *s, f32 dt);
aether_vec3_t aethertracer_current_position(const aethertracer_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
