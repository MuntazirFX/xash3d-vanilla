#ifndef AETHER_AETHERFIRE_H
#define AETHER_AETHERFIRE_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherfire_state { bool enabled; f32 value; u32 events; char text[128]; } aetherfire_state_t;
void aetherfire_init(aetherfire_state_t *s);
void aetherfire_update(aetherfire_state_t *s, f32 dt);
void aetherfire_reset(aetherfire_state_t *s);
void aetherfire_event(aetherfire_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
