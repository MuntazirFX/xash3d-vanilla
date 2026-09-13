#ifndef AETHER_AETHERBREAKABLE_H
#define AETHER_AETHERBREAKABLE_H
#include "../core/AetherCore.h"
#include "../core/AetherMath.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherbreakable_state { bool enabled; f32 value; aether_vec3_t position,velocity; } aetherbreakable_state_t;
void aetherbreakable_init(aetherbreakable_state_t *s);
void aetherbreakable_update(aetherbreakable_state_t *s, f32 dt);
void aetherbreakable_reset(aetherbreakable_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
