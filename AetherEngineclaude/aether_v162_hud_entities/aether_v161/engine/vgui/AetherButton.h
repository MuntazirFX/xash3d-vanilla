#ifndef AETHER_AETHERBUTTON_H
#define AETHER_AETHERBUTTON_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherbutton_state { bool enabled; f32 value; u32 events; char text[128]; } aetherbutton_state_t;
void aetherbutton_init(aetherbutton_state_t *s);
void aetherbutton_update(aetherbutton_state_t *s, f32 dt);
void aetherbutton_reset(aetherbutton_state_t *s);
void aetherbutton_event(aetherbutton_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
