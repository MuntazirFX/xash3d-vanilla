#ifndef AETHER_AETHERTEXTINPUT_H
#define AETHER_AETHERTEXTINPUT_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethertextinput_state { bool enabled; f32 value; u32 events; char text[128]; } aethertextinput_state_t;
void aethertextinput_init(aethertextinput_state_t *s);
void aethertextinput_update(aethertextinput_state_t *s, f32 dt);
void aethertextinput_reset(aethertextinput_state_t *s);
void aethertextinput_event(aethertextinput_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
