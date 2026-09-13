#ifndef AETHER_AETHERBLOOD_H
#define AETHER_AETHERBLOOD_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherblood_state { bool enabled; f32 value; u32 events; char text[128]; } aetherblood_state_t;
void aetherblood_init(aetherblood_state_t *s);
void aetherblood_update(aetherblood_state_t *s, f32 dt);
void aetherblood_reset(aetherblood_state_t *s);
void aetherblood_event(aetherblood_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
