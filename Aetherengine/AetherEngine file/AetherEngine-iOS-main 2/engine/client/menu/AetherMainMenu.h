#ifndef AETHER_AETHERMAINMENU_H
#define AETHER_AETHERMAINMENU_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethermainmenu_state { bool enabled; f32 value; u32 events; char text[128]; } aethermainmenu_state_t;
void aethermainmenu_init(aethermainmenu_state_t *s);
void aethermainmenu_update(aethermainmenu_state_t *s, f32 dt);
void aethermainmenu_reset(aethermainmenu_state_t *s);
void aethermainmenu_event(aethermainmenu_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
