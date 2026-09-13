#ifndef AETHER_AETHERTIMER_H
#define AETHER_AETHERTIMER_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethertimer_state { bool enabled; f32 value; u32 events; char text[128]; } aethertimer_state_t;
void aethertimer_init(aethertimer_state_t *s);
void aethertimer_update(aethertimer_state_t *s, f32 dt);
void aethertimer_reset(aethertimer_state_t *s);
void aethertimer_event(aethertimer_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
