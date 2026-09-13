#ifndef AETHER_AETHERENVGLOW_H
#define AETHER_AETHERENVGLOW_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherenvglow_state { bool enabled; f32 value; u32 events; char text[128]; } aetherenvglow_state_t;
void aetherenvglow_init(aetherenvglow_state_t *s);
void aetherenvglow_update(aetherenvglow_state_t *s, f32 dt);
void aetherenvglow_reset(aetherenvglow_state_t *s);
void aetherenvglow_event(aetherenvglow_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
