#ifndef AETHER_SCORE_H
#define AETHER_SCORE_H
#include "../../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherscore_state {
    i32 kills, deaths;
    f32 kd_ratio;   /* recomputed on every change; deaths==0 -> equals kills */
} aetherscore_state_t;
void aetherscore_init(aetherscore_state_t *s);
void aetherscore_add_kill(aetherscore_state_t *s);
void aetherscore_add_death(aetherscore_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
