#ifndef AETHER_LIGHTNING_H
#define AETHER_LIGHTNING_H
#include "../../core/AetherCore.h"
#include "../../core/AetherMath.h"
#ifdef __cplusplus
extern "C" {
#endif
#define AETHER_LIGHTNING_SEGMENTS 6
typedef struct aetherlightning_state {
    aether_vec3_t start, end;
    aether_vec3_t jitter_seed[AETHER_LIGHTNING_SEGMENTS]; /* per-segment offset, refreshed each strike */
    f32 life;
    bool active;
} aetherlightning_state_t;
void aetherlightning_init(aetherlightning_state_t *s);
void aetherlightning_strike(aetherlightning_state_t *s, aether_vec3_t start, aether_vec3_t end, u32 seed);
void aetherlightning_update(aetherlightning_state_t *s, f32 dt);
#ifdef __cplusplus
}
#endif
#endif
