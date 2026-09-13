#ifndef AETHER_AETHERGAMERULES_H
#define AETHER_AETHERGAMERULES_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethergamerules_state { bool enabled; f32 value; u32 events; char text[128]; } aethergamerules_state_t;
void aethergamerules_init(aethergamerules_state_t *s);
void aethergamerules_update(aethergamerules_state_t *s, f32 dt);
void aethergamerules_reset(aethergamerules_state_t *s);
void aethergamerules_event(aethergamerules_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
