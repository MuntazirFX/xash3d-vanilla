#ifndef AETHER_AETHERLOCALIZATION_H
#define AETHER_AETHERLOCALIZATION_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherlocalization_state { bool enabled; f32 value; u32 events; char text[128]; } aetherlocalization_state_t;
void aetherlocalization_init(aetherlocalization_state_t *s);
void aetherlocalization_update(aetherlocalization_state_t *s, f32 dt);
void aetherlocalization_reset(aetherlocalization_state_t *s);
void aetherlocalization_event(aetherlocalization_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
