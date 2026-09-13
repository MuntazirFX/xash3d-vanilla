#ifndef AETHER_AETHERIMAGE_H
#define AETHER_AETHERIMAGE_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherimage_state { bool enabled; f32 value; u32 events; char text[128]; } aetherimage_state_t;
void aetherimage_init(aetherimage_state_t *s);
void aetherimage_update(aetherimage_state_t *s, f32 dt);
void aetherimage_reset(aetherimage_state_t *s);
void aetherimage_event(aetherimage_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
