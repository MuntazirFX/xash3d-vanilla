#ifndef AETHER_AETHERSTATEMACHINE_H
#define AETHER_AETHERSTATEMACHINE_H
#include "../../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherstatemachine_state { bool enabled; f32 value; u32 events; char text[128]; } aetherstatemachine_state_t;
void aetherstatemachine_init(aetherstatemachine_state_t *s);
void aetherstatemachine_update(aetherstatemachine_state_t *s, f32 dt);
void aetherstatemachine_reset(aetherstatemachine_state_t *s);
void aetherstatemachine_event(aetherstatemachine_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
