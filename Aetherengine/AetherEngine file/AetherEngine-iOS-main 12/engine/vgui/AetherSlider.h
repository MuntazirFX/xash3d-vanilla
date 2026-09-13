#ifndef AETHER_AETHERSLIDER_H
#define AETHER_AETHERSLIDER_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherslider_state { bool enabled; f32 value; u32 events; char text[128]; } aetherslider_state_t;
void aetherslider_init(aetherslider_state_t *s);
void aetherslider_update(aetherslider_state_t *s, f32 dt);
void aetherslider_reset(aetherslider_state_t *s);
void aetherslider_event(aetherslider_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
