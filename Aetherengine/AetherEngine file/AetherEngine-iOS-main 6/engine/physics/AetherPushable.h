#ifndef AETHER_AETHERPUSHABLE_H
#define AETHER_AETHERPUSHABLE_H
#include "../core/AetherCore.h"
#include "../core/AetherMath.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherpushable_state { bool enabled; f32 value; aether_vec3_t position,velocity; } aetherpushable_state_t;
void aetherpushable_init(aetherpushable_state_t *s);
void aetherpushable_update(aetherpushable_state_t *s, f32 dt);
void aetherpushable_reset(aetherpushable_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
