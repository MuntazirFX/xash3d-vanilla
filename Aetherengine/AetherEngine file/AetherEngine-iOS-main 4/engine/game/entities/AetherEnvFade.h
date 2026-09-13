#ifndef AETHER_AETHERENVFADE_H
#define AETHER_AETHERENVFADE_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherenvfade_state { bool enabled; f32 value; u32 events; char text[128]; } aetherenvfade_state_t;
void aetherenvfade_init(aetherenvfade_state_t *s);
void aetherenvfade_update(aetherenvfade_state_t *s, f32 dt);
void aetherenvfade_reset(aetherenvfade_state_t *s);
void aetherenvfade_event(aetherenvfade_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
