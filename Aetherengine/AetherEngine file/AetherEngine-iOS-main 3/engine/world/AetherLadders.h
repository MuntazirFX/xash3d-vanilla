#ifndef AETHER_AETHERLADDERS_H
#define AETHER_AETHERLADDERS_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherladders_state { bool enabled; f32 value; u32 events; char text[128]; } aetherladders_state_t;
void aetherladders_init(aetherladders_state_t *s);
void aetherladders_update(aetherladders_state_t *s, f32 dt);
void aetherladders_reset(aetherladders_state_t *s);
void aetherladders_event(aetherladders_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
