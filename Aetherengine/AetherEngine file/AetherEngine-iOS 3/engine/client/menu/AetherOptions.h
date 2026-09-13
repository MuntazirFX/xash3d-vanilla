#ifndef AETHER_AETHEROPTIONS_H
#define AETHER_AETHEROPTIONS_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetheroptions_state { bool enabled; f32 value; u32 events; char text[128]; } aetheroptions_state_t;
void aetheroptions_init(aetheroptions_state_t *s);
void aetheroptions_update(aetheroptions_state_t *s, f32 dt);
void aetheroptions_reset(aetheroptions_state_t *s);
void aetheroptions_event(aetheroptions_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
