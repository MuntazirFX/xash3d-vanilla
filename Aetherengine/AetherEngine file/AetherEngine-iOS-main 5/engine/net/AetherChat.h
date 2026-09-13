#ifndef AETHER_AETHERCHAT_H
#define AETHER_AETHERCHAT_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherchat_state { bool enabled; f32 value; u32 events; char text[128]; } aetherchat_state_t;
void aetherchat_init(aetherchat_state_t *s);
void aetherchat_update(aetherchat_state_t *s, f32 dt);
void aetherchat_reset(aetherchat_state_t *s);
void aetherchat_event(aetherchat_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
