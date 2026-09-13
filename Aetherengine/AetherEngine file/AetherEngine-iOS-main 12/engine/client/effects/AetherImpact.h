#ifndef AETHER_AETHERIMPACT_H
#define AETHER_AETHERIMPACT_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherimpact_state { bool enabled; f32 value; u32 events; char text[128]; } aetherimpact_state_t;
void aetherimpact_init(aetherimpact_state_t *s);
void aetherimpact_update(aetherimpact_state_t *s, f32 dt);
void aetherimpact_reset(aetherimpact_state_t *s);
void aetherimpact_event(aetherimpact_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
