#ifndef AETHER_AETHERLOADING_H
#define AETHER_AETHERLOADING_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherloading_state { bool enabled; f32 value; u32 events; char text[128]; } aetherloading_state_t;
void aetherloading_init(aetherloading_state_t *s);
void aetherloading_update(aetherloading_state_t *s, f32 dt);
void aetherloading_reset(aetherloading_state_t *s);
void aetherloading_event(aetherloading_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
