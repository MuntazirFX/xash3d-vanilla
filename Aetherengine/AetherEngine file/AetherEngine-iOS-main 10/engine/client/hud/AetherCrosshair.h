#ifndef AETHER_AETHERCROSSHAIR_H
#define AETHER_AETHERCROSSHAIR_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethercrosshair_state { bool enabled; f32 value; u32 events; char text[128]; } aethercrosshair_state_t;
void aethercrosshair_init(aethercrosshair_state_t *s);
void aethercrosshair_update(aethercrosshair_state_t *s, f32 dt);
void aethercrosshair_reset(aethercrosshair_state_t *s);
void aethercrosshair_event(aethercrosshair_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
