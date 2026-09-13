#ifndef AETHER_AETHERSAVEUI_H
#define AETHER_AETHERSAVEUI_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethersaveui_state { bool enabled; f32 value; u32 events; char text[128]; } aethersaveui_state_t;
void aethersaveui_init(aethersaveui_state_t *s);
void aethersaveui_update(aethersaveui_state_t *s, f32 dt);
void aethersaveui_reset(aethersaveui_state_t *s);
void aethersaveui_event(aethersaveui_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
