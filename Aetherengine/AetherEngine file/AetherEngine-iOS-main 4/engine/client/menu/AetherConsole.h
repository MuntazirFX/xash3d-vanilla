#ifndef AETHER_AETHERCONSOLE_H
#define AETHER_AETHERCONSOLE_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherconsole_state { bool enabled; f32 value; u32 events; char text[128]; } aetherconsole_state_t;
void aetherconsole_init(aetherconsole_state_t *s);
void aetherconsole_update(aetherconsole_state_t *s, f32 dt);
void aetherconsole_reset(aetherconsole_state_t *s);
void aetherconsole_event(aetherconsole_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
