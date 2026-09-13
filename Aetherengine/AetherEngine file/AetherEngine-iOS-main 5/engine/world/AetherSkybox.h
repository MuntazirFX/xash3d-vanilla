#ifndef AETHER_AETHERSKYBOX_H
#define AETHER_AETHERSKYBOX_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherskybox_state { bool enabled; f32 value; u32 events; char text[128]; } aetherskybox_state_t;
void aetherskybox_init(aetherskybox_state_t *s);
void aetherskybox_update(aetherskybox_state_t *s, f32 dt);
void aetherskybox_reset(aetherskybox_state_t *s);
void aetherskybox_event(aetherskybox_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
