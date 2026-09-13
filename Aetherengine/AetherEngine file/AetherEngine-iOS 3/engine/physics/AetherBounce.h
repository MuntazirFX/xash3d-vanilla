#ifndef AETHER_AETHERBOUNCE_H
#define AETHER_AETHERBOUNCE_H
#include "../core/AetherCore.h"
#include "../core/AetherMath.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherbounce_state { bool enabled; f32 value; aether_vec3_t position,velocity; } aetherbounce_state_t;
void aetherbounce_init(aetherbounce_state_t *s);
void aetherbounce_update(aetherbounce_state_t *s, f32 dt);
void aetherbounce_reset(aetherbounce_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
