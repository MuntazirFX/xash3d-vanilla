#ifndef AETHER_AETHERPATHFIND_H
#define AETHER_AETHERPATHFIND_H
#include "../../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherpathfind_state { bool enabled; f32 value; u32 events; char text[128]; } aetherpathfind_state_t;
void aetherpathfind_init(aetherpathfind_state_t *s);
void aetherpathfind_update(aetherpathfind_state_t *s, f32 dt);
void aetherpathfind_reset(aetherpathfind_state_t *s);
void aetherpathfind_event(aetherpathfind_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
