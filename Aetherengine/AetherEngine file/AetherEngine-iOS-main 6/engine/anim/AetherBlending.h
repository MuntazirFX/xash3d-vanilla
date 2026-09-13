#ifndef AETHER_AETHERBLENDING_H
#define AETHER_AETHERBLENDING_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherblending_state { bool enabled; f32 value; u32 events; char text[128]; } aetherblending_state_t;
void aetherblending_init(aetherblending_state_t *s);
void aetherblending_update(aetherblending_state_t *s, f32 dt);
void aetherblending_reset(aetherblending_state_t *s);
void aetherblending_event(aetherblending_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
