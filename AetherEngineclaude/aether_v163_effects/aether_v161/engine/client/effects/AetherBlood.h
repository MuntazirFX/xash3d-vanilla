#ifndef AETHER_BLOOD_H
#define AETHER_BLOOD_H
#include "../../core/AetherCore.h"
#include "../../core/AetherMath.h"
#ifdef __cplusplus
extern "C" {
#endif
#define AETHER_BLOOD_MAX 32
typedef struct { aether_vec3_t position; f32 size, life; } aether_blood_decal_t;
typedef struct aetherblood_state {
    aether_blood_decal_t decals[AETHER_BLOOD_MAX];
    u32 count;
} aetherblood_state_t;
void aetherblood_init(aetherblood_state_t *s);
/* Splatter size scales with damage dealt; bigger hits leave bigger decals. */
void aetherblood_spawn(aetherblood_state_t *s, aether_vec3_t position, f32 damage);
void aetherblood_update(aetherblood_state_t *s, f32 dt);
#ifdef __cplusplus
}
#endif
#endif
