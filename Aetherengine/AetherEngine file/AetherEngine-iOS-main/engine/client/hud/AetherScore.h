#ifndef AETHER_AETHERSCORE_H
#define AETHER_AETHERSCORE_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherscore_state { bool enabled; f32 value; u32 events; char text[128]; } aetherscore_state_t;
void aetherscore_init(aetherscore_state_t *s);
void aetherscore_update(aetherscore_state_t *s, f32 dt);
void aetherscore_reset(aetherscore_state_t *s);
void aetherscore_event(aetherscore_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
