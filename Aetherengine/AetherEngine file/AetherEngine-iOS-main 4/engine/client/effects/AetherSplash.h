#ifndef AETHER_AETHERSPLASH_H
#define AETHER_AETHERSPLASH_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethersplash_state { bool enabled; f32 value; u32 events; char text[128]; } aethersplash_state_t;
void aethersplash_init(aethersplash_state_t *s);
void aethersplash_update(aethersplash_state_t *s, f32 dt);
void aethersplash_reset(aethersplash_state_t *s);
void aethersplash_event(aethersplash_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
