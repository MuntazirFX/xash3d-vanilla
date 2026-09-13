#ifndef AETHER_BULLETHOLES_H
#define AETHER_BULLETHOLES_H
#include "../../core/AetherCore.h"
#include "../../core/AetherMath.h"
#ifdef __cplusplus
extern "C" {
#endif
#define AETHER_BULLETHOLES_MAX 64
typedef struct { aether_vec3_t position, normal; } aether_bullethole_t;
typedef struct aetherbulletholes_state {
    aether_bullethole_t holes[AETHER_BULLETHOLES_MAX];
    u32 count;
    u32 next_slot; /* ring buffer cursor for oldest-first recycling */
} aetherbulletholes_state_t;
void aetherbulletholes_init(aetherbulletholes_state_t *s);
void aetherbulletholes_spawn(aetherbulletholes_state_t *s, aether_vec3_t position, aether_vec3_t normal);
#ifdef __cplusplus
}
#endif
#endif
