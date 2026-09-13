#ifndef AETHER_AETHERHLSDK_H
#define AETHER_AETHERHLSDK_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherhlsdk_state { bool enabled; f32 value; u32 events; char text[128]; } aetherhlsdk_state_t;
void aetherhlsdk_init(aetherhlsdk_state_t *s);
void aetherhlsdk_update(aetherhlsdk_state_t *s, f32 dt);
void aetherhlsdk_reset(aetherhlsdk_state_t *s);
void aetherhlsdk_event(aetherhlsdk_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
