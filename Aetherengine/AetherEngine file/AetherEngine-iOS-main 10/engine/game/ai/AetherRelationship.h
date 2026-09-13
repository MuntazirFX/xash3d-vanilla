#ifndef AETHER_AETHERRELATIONSHIP_H
#define AETHER_AETHERRELATIONSHIP_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherrelationship_state { bool enabled; f32 value; u32 events; char text[128]; } aetherrelationship_state_t;
void aetherrelationship_init(aetherrelationship_state_t *s);
void aetherrelationship_update(aetherrelationship_state_t *s, f32 dt);
void aetherrelationship_reset(aetherrelationship_state_t *s);
void aetherrelationship_event(aetherrelationship_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
