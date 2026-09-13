#ifndef AETHER_AETHERENVEFFECTS_H
#define AETHER_AETHERENVEFFECTS_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherenveffects_state { bool enabled; f32 value; u32 events; char text[128]; } aetherenveffects_state_t;
void aetherenveffects_init(aetherenveffects_state_t *s);
void aetherenveffects_update(aetherenveffects_state_t *s, f32 dt);
void aetherenveffects_reset(aetherenveffects_state_t *s);
void aetherenveffects_event(aetherenveffects_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
