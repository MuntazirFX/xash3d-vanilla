#ifndef AETHER_AETHERTRANSITION_H
#define AETHER_AETHERTRANSITION_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethertransition_state { bool enabled; f32 value; u32 events; char text[128]; } aethertransition_state_t;
void aethertransition_init(aethertransition_state_t *s);
void aethertransition_update(aethertransition_state_t *s, f32 dt);
void aethertransition_reset(aethertransition_state_t *s);
void aethertransition_event(aethertransition_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
