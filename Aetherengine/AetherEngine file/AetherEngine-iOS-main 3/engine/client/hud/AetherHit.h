#ifndef AETHER_AETHERHIT_H
#define AETHER_AETHERHIT_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherhit_state { bool enabled; f32 value; u32 events; char text[128]; } aetherhit_state_t;
void aetherhit_init(aetherhit_state_t *s);
void aetherhit_update(aetherhit_state_t *s, f32 dt);
void aetherhit_reset(aetherhit_state_t *s);
void aetherhit_event(aetherhit_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
