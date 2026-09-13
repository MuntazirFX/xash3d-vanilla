#ifndef AETHER_AETHERFUNCPUSHABLE_H
#define AETHER_AETHERFUNCPUSHABLE_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherfuncpushable_state { bool enabled; f32 value; u32 events; char text[128]; } aetherfuncpushable_state_t;
void aetherfuncpushable_init(aetherfuncpushable_state_t *s);
void aetherfuncpushable_update(aetherfuncpushable_state_t *s, f32 dt);
void aetherfuncpushable_reset(aetherfuncpushable_state_t *s);
void aetherfuncpushable_event(aetherfuncpushable_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
