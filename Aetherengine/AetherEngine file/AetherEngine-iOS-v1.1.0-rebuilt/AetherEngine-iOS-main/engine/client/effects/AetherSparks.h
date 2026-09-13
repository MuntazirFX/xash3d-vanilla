#ifndef AETHER_AETHERSPARKS_H
#define AETHER_AETHERSPARKS_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethersparks_state { bool enabled; f32 value; u32 events; char text[128]; } aethersparks_state_t;
void aethersparks_init(aethersparks_state_t *s);
void aethersparks_update(aethersparks_state_t *s, f32 dt);
void aethersparks_reset(aethersparks_state_t *s);
void aethersparks_event(aethersparks_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
