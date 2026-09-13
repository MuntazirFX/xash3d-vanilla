#ifndef AETHER_AETHERSEQUENCE_H
#define AETHER_AETHERSEQUENCE_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethersequence_state { bool enabled; f32 value; u32 events; char text[128]; } aethersequence_state_t;
void aethersequence_init(aethersequence_state_t *s);
void aethersequence_update(aethersequence_state_t *s, f32 dt);
void aethersequence_reset(aethersequence_state_t *s);
void aethersequence_event(aethersequence_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
