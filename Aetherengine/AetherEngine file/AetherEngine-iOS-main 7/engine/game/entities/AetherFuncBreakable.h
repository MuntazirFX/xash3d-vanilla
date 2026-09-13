#ifndef AETHER_AETHERFUNCBREAKABLE_H
#define AETHER_AETHERFUNCBREAKABLE_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherfuncbreakable_state { bool enabled; f32 value; u32 events; char text[128]; } aetherfuncbreakable_state_t;
void aetherfuncbreakable_init(aetherfuncbreakable_state_t *s);
void aetherfuncbreakable_update(aetherfuncbreakable_state_t *s, f32 dt);
void aetherfuncbreakable_reset(aetherfuncbreakable_state_t *s);
void aetherfuncbreakable_event(aetherfuncbreakable_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
