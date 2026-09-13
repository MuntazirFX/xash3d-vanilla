#ifndef AETHER_SPLASH_H
#define AETHER_SPLASH_H
#include "../../core/AetherCore.h"
#include "../../core/AetherMath.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethersplash_state {
    aether_vec3_t position;
    f32 size;     /* scales with entry speed */
    f32 life;
    bool active;
} aethersplash_state_t;
void aethersplash_init(aethersplash_state_t *s);
/* entry_speed: magnitude of velocity at the moment of crossing the water plane. */
void aethersplash_spawn(aethersplash_state_t *s, aether_vec3_t position, f32 entry_speed);
void aethersplash_update(aethersplash_state_t *s, f32 dt);
#ifdef __cplusplus
}
#endif
#endif
