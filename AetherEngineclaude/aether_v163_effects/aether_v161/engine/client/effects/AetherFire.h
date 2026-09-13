#ifndef AETHER_FIRE_H
#define AETHER_FIRE_H
#include "../../core/AetherCore.h"
#include "../../core/AetherMath.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherfire_state {
    aether_vec3_t position;
    f32 radius;
    f32 damage_per_sec;
    f32 duration, age;
    bool active;
} aetherfire_state_t;
void aetherfire_init(aetherfire_state_t *s);
void aetherfire_ignite(aetherfire_state_t *s, aether_vec3_t position, f32 radius, f32 duration);
void aetherfire_update(aetherfire_state_t *s, f32 dt);
bool aetherfire_burns(const aetherfire_state_t *s, aether_vec3_t point);
#ifdef __cplusplus
}
#endif
#endif
