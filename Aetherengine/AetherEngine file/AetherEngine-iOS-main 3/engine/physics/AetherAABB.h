#ifndef AETHER_AETHERAABB_H
#define AETHER_AETHERAABB_H
#include "../core/AetherCore.h"
#include "../core/AetherMath.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetheraabb_state { bool enabled; f32 value; aether_vec3_t position,velocity; } aetheraabb_state_t;
void aetheraabb_init(aetheraabb_state_t *s);
void aetheraabb_update(aetheraabb_state_t *s, f32 dt);
void aetheraabb_reset(aetheraabb_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
