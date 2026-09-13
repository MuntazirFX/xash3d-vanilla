#ifndef AETHER_AETHERHEALTH_H
#define AETHER_AETHERHEALTH_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherhealth_state { bool enabled; f32 value; u32 events; char text[128]; } aetherhealth_state_t;
void aetherhealth_init(aetherhealth_state_t *s);
void aetherhealth_update(aetherhealth_state_t *s, f32 dt);
void aetherhealth_reset(aetherhealth_state_t *s);
void aetherhealth_event(aetherhealth_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
