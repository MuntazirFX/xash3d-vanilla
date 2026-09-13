#ifndef AETHER_AETHERTABPANEL_H
#define AETHER_AETHERTABPANEL_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethertabpanel_state { bool enabled; f32 value; u32 events; char text[128]; } aethertabpanel_state_t;
void aethertabpanel_init(aethertabpanel_state_t *s);
void aethertabpanel_update(aethertabpanel_state_t *s, f32 dt);
void aethertabpanel_reset(aethertabpanel_state_t *s);
void aethertabpanel_event(aethertabpanel_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
