#ifndef AETHER_AETHERBREAK_H
#define AETHER_AETHERBREAK_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherbreak_state { bool enabled; f32 value; u32 events; char text[128]; } aetherbreak_state_t;
void aetherbreak_init(aetherbreak_state_t *s);
void aetherbreak_update(aetherbreak_state_t *s, f32 dt);
void aetherbreak_reset(aetherbreak_state_t *s);
void aetherbreak_event(aetherbreak_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
