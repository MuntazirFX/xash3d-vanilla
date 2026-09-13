#ifndef AETHER_AETHERQUICKSAVE_H
#define AETHER_AETHERQUICKSAVE_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherquicksave_state { bool enabled; f32 value; u32 events; char text[128]; } aetherquicksave_state_t;
void aetherquicksave_init(aetherquicksave_state_t *s);
void aetherquicksave_update(aetherquicksave_state_t *s, f32 dt);
void aetherquicksave_reset(aetherquicksave_state_t *s);
void aetherquicksave_event(aetherquicksave_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
