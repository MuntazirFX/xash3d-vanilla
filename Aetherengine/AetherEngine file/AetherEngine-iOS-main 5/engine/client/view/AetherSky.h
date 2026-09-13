#ifndef AETHER_AETHERSKY_H
#define AETHER_AETHERSKY_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethersky_state { bool enabled; f32 value; u32 events; char text[128]; } aethersky_state_t;
void aethersky_init(aethersky_state_t *s);
void aethersky_update(aethersky_state_t *s, f32 dt);
void aethersky_reset(aethersky_state_t *s);
void aethersky_event(aethersky_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
