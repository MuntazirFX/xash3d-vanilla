#ifndef AETHER_HIT_H
#define AETHER_HIT_H
#include "../../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherhit_state {
    f32  marker_life;   /* seconds remaining that the hitmarker should render */
    bool was_kill;       /* true = show the "kill confirmed" variant (bigger/colored) */
} aetherhit_state_t;
void aetherhit_init(aetherhit_state_t *s);
void aetherhit_register(aetherhit_state_t *s, bool killed_target);
void aetherhit_update(aetherhit_state_t *s, f32 dt);
bool aetherhit_visible(const aetherhit_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
