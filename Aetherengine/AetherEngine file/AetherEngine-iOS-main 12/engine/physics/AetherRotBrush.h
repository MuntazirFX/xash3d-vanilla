#ifndef AETHER_AETHERROTBRUSH_H
#define AETHER_AETHERROTBRUSH_H
#include "../core/AetherCore.h"
#include "../core/AetherMath.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherrotbrush_state { bool enabled; f32 value; aether_vec3_t position,velocity; } aetherrotbrush_state_t;
void aetherrotbrush_init(aetherrotbrush_state_t *s);
void aetherrotbrush_update(aetherrotbrush_state_t *s, f32 dt);
void aetherrotbrush_reset(aetherrotbrush_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
