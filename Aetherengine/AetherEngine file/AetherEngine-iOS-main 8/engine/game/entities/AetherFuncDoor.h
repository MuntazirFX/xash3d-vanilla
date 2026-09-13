#ifndef AETHER_AETHERFUNCDOOR_H
#define AETHER_AETHERFUNCDOOR_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherfuncdoor_state { bool enabled; f32 value; u32 events; char text[128]; } aetherfuncdoor_state_t;
void aetherfuncdoor_init(aetherfuncdoor_state_t *s);
void aetherfuncdoor_update(aetherfuncdoor_state_t *s, f32 dt);
void aetherfuncdoor_reset(aetherfuncdoor_state_t *s);
void aetherfuncdoor_event(aetherfuncdoor_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
