#ifndef AETHER_AETHERMENU_H
#define AETHER_AETHERMENU_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethermenu_state { bool enabled; f32 value; u32 events; char text[128]; } aethermenu_state_t;
void aethermenu_init(aethermenu_state_t *s);
void aethermenu_update(aethermenu_state_t *s, f32 dt);
void aethermenu_reset(aethermenu_state_t *s);
void aethermenu_event(aethermenu_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
