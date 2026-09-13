#ifndef AETHER_AETHEROBJECTIVES_H
#define AETHER_AETHEROBJECTIVES_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherobjectives_state { bool enabled; f32 value; u32 events; char text[128]; } aetherobjectives_state_t;
void aetherobjectives_init(aetherobjectives_state_t *s);
void aetherobjectives_update(aetherobjectives_state_t *s, f32 dt);
void aetherobjectives_reset(aetherobjectives_state_t *s);
void aetherobjectives_event(aetherobjectives_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
