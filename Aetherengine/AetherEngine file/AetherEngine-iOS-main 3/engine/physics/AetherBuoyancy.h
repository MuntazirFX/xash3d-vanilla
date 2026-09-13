#ifndef AETHER_AETHERBUOYANCY_H
#define AETHER_AETHERBUOYANCY_H
#include "../core/AetherCore.h"
#include "../core/AetherMath.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherbuoyancy_state { bool enabled; f32 value; aether_vec3_t position,velocity; } aetherbuoyancy_state_t;
void aetherbuoyancy_init(aetherbuoyancy_state_t *s);
void aetherbuoyancy_update(aetherbuoyancy_state_t *s, f32 dt);
void aetherbuoyancy_reset(aetherbuoyancy_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
