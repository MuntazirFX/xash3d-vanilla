#ifndef AETHER_AETHERDOORSND_H
#define AETHER_AETHERDOORSND_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherdoorsnd_state { bool enabled; f32 value; u32 events; char text[128]; } aetherdoorsnd_state_t;
void aetherdoorsnd_init(aetherdoorsnd_state_t *s);
void aetherdoorsnd_update(aetherdoorsnd_state_t *s, f32 dt);
void aetherdoorsnd_reset(aetherdoorsnd_state_t *s);
void aetherdoorsnd_event(aetherdoorsnd_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
