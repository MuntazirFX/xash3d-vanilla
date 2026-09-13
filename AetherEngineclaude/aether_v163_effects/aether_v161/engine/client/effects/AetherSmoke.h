#ifndef AETHER_SMOKE_H
#define AETHER_SMOKE_H
#include "../../core/AetherCore.h"
#include "../../core/AetherMath.h"
#ifdef __cplusplus
extern "C" {
#endif
#define AETHER_SMOKE_MAX 16
typedef struct { aether_vec3_t position; f32 size, life, max_life; } aether_smoke_puff_t;
typedef struct aethersmoke_state {
    aether_smoke_puff_t puffs[AETHER_SMOKE_MAX];
    u32 count;
} aethersmoke_state_t;
void aethersmoke_init(aethersmoke_state_t *s);
void aethersmoke_spawn(aethersmoke_state_t *s, aether_vec3_t position);
void aethersmoke_update(aethersmoke_state_t *s, f32 dt);
/* 0..1 fade-out alpha for renderer, based on remaining life. */
f32  aethersmoke_alpha(const aether_smoke_puff_t *puff);
#ifdef __cplusplus
}
#endif
#endif
