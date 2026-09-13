#include "AetherLightning.h"
#include <string.h>
void aetherlightning_init(aetherlightning_state_t *s) { if (s) memset(s, 0, sizeof *s); }
void aetherlightning_strike(aetherlightning_state_t *s, aether_vec3_t start, aether_vec3_t end, u32 seed) {
    if (!s) return;
    s->start = start; s->end = end;
    /* cheap deterministic pseudo-random jitter per segment from the seed, so
     * the same seed always reproduces the same bolt shape (network-friendly). */
    u32 x = seed ? seed : 1;
    for (u32 i = 0; i < AETHER_LIGHTNING_SEGMENTS; i++) {
        x ^= x << 13; x ^= x >> 17; x ^= x << 5;
        s->jitter_seed[i].x = (f32)((i32)(x % 21) - 10);
        x ^= x << 13; x ^= x >> 17; x ^= x << 5;
        s->jitter_seed[i].y = (f32)((i32)(x % 21) - 10);
        s->jitter_seed[i].z = 0;
    }
    s->life = 0.15f;
    s->active = true;
}
void aetherlightning_update(aetherlightning_state_t *s, f32 dt) {
    if (!s || !s->active) return;
    s->life -= dt;
    if (s->life <= 0) s->active = false;
}
