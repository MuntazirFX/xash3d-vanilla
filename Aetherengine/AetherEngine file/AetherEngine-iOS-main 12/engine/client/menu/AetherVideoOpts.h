#ifndef AETHER_AETHERVIDEOOPTS_H
#define AETHER_AETHERVIDEOOPTS_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethervideoopts_state { bool enabled; f32 value; u32 events; char text[128]; } aethervideoopts_state_t;
void aethervideoopts_init(aethervideoopts_state_t *s);
void aethervideoopts_update(aethervideoopts_state_t *s, f32 dt);
void aethervideoopts_reset(aethervideoopts_state_t *s);
void aethervideoopts_event(aethervideoopts_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
