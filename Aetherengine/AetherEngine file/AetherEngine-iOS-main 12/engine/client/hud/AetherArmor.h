#ifndef AETHER_AETHERARMOR_H
#define AETHER_AETHERARMOR_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherarmor_state { bool enabled; f32 value; u32 events; char text[128]; } aetherarmor_state_t;
void aetherarmor_init(aetherarmor_state_t *s);
void aetherarmor_update(aetherarmor_state_t *s, f32 dt);
void aetherarmor_reset(aetherarmor_state_t *s);
void aetherarmor_event(aetherarmor_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
