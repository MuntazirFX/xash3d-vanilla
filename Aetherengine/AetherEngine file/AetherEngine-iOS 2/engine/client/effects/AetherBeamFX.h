#ifndef AETHER_AETHERBEAMFX_H
#define AETHER_AETHERBEAMFX_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherbeamfx_state { bool enabled; f32 value; u32 events; char text[128]; } aetherbeamfx_state_t;
void aetherbeamfx_init(aetherbeamfx_state_t *s);
void aetherbeamfx_update(aetherbeamfx_state_t *s, f32 dt);
void aetherbeamfx_reset(aetherbeamfx_state_t *s);
void aetherbeamfx_event(aetherbeamfx_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
