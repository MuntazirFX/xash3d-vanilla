#ifndef AETHER_AETHERLIGHT_H
#define AETHER_AETHERLIGHT_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherlight_state { bool enabled; f32 value; u32 events; char text[128]; } aetherlight_state_t;
void aetherlight_init(aetherlight_state_t *s);
void aetherlight_update(aetherlight_state_t *s, f32 dt);
void aetherlight_reset(aetherlight_state_t *s);
void aetherlight_event(aetherlight_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
