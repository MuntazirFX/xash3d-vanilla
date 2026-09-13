#ifndef AETHER_AETHERFUNCBUTTON_H
#define AETHER_AETHERFUNCBUTTON_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherfuncbutton_state { bool enabled; f32 value; u32 events; char text[128]; } aetherfuncbutton_state_t;
void aetherfuncbutton_init(aetherfuncbutton_state_t *s);
void aetherfuncbutton_update(aetherfuncbutton_state_t *s, f32 dt);
void aetherfuncbutton_reset(aetherfuncbutton_state_t *s);
void aetherfuncbutton_event(aetherfuncbutton_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
