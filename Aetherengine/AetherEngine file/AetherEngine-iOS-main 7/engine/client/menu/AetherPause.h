#ifndef AETHER_AETHERPAUSE_H
#define AETHER_AETHERPAUSE_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherpause_state { bool enabled; f32 value; u32 events; char text[128]; } aetherpause_state_t;
void aetherpause_init(aetherpause_state_t *s);
void aetherpause_update(aetherpause_state_t *s, f32 dt);
void aetherpause_reset(aetherpause_state_t *s);
void aetherpause_event(aetherpause_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
