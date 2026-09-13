#ifndef AETHER_AETHERTRANSSURF_H
#define AETHER_AETHERTRANSSURF_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethertranssurf_state { bool enabled; f32 value; u32 events; char text[128]; } aethertranssurf_state_t;
void aethertranssurf_init(aethertranssurf_state_t *s);
void aethertranssurf_update(aethertranssurf_state_t *s, f32 dt);
void aethertranssurf_reset(aethertranssurf_state_t *s);
void aethertranssurf_event(aethertranssurf_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
