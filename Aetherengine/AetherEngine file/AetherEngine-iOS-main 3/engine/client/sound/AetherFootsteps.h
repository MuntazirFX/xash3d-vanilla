#ifndef AETHER_AETHERFOOTSTEPS_H
#define AETHER_AETHERFOOTSTEPS_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherfootsteps_state { bool enabled; f32 value; u32 events; char text[128]; } aetherfootsteps_state_t;
void aetherfootsteps_init(aetherfootsteps_state_t *s);
void aetherfootsteps_update(aetherfootsteps_state_t *s, f32 dt);
void aetherfootsteps_reset(aetherfootsteps_state_t *s);
void aetherfootsteps_event(aetherfootsteps_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
