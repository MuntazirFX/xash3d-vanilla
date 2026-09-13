#ifndef AETHER_AETHERTRIGGERCHANGE_H
#define AETHER_AETHERTRIGGERCHANGE_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethertriggerchange_state { bool enabled; f32 value; u32 events; char text[128]; } aethertriggerchange_state_t;
void aethertriggerchange_init(aethertriggerchange_state_t *s);
void aethertriggerchange_update(aethertriggerchange_state_t *s, f32 dt);
void aethertriggerchange_reset(aethertriggerchange_state_t *s);
void aethertriggerchange_event(aethertriggerchange_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
