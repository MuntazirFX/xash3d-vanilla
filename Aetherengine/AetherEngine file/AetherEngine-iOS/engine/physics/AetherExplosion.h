#ifndef AETHER_AETHEREXPLOSION_H
#define AETHER_AETHEREXPLOSION_H
#include "../core/AetherCore.h"
#include "../core/AetherMath.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherexplosion_state { bool enabled; f32 value; aether_vec3_t position,velocity; } aetherexplosion_state_t;
void aetherexplosion_init(aetherexplosion_state_t *s);
void aetherexplosion_update(aetherexplosion_state_t *s, f32 dt);
void aetherexplosion_reset(aetherexplosion_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
