#ifndef AETHER_AETHERVIEWPUNCH_H
#define AETHER_AETHERVIEWPUNCH_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherviewpunch_state { bool enabled; f32 value; u32 events; char text[128]; } aetherviewpunch_state_t;
void aetherviewpunch_init(aetherviewpunch_state_t *s);
void aetherviewpunch_update(aetherviewpunch_state_t *s, f32 dt);
void aetherviewpunch_reset(aetherviewpunch_state_t *s);
void aetherviewpunch_event(aetherviewpunch_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
