#ifndef AETHER_AETHER3DAUDIO_H
#define AETHER_AETHER3DAUDIO_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aether3daudio_state { bool enabled; f32 value; u32 events; char text[128]; } aether3daudio_state_t;
void aether3daudio_init(aether3daudio_state_t *s);
void aether3daudio_update(aether3daudio_state_t *s, f32 dt);
void aether3daudio_reset(aether3daudio_state_t *s);
void aether3daudio_event(aether3daudio_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
