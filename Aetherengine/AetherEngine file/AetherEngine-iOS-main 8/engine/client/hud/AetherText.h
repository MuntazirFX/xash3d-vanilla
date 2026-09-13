#ifndef AETHER_AETHERTEXT_H
#define AETHER_AETHERTEXT_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethertext_state { bool enabled; f32 value; u32 events; char text[128]; } aethertext_state_t;
void aethertext_init(aethertext_state_t *s);
void aethertext_update(aethertext_state_t *s, f32 dt);
void aethertext_reset(aethertext_state_t *s);
void aethertext_event(aethertext_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
