#ifndef AETHER_AETHERFONT_H
#define AETHER_AETHERFONT_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherfont_state { bool enabled; f32 value; u32 events; char text[128]; } aetherfont_state_t;
void aetherfont_init(aetherfont_state_t *s);
void aetherfont_update(aetherfont_state_t *s, f32 dt);
void aetherfont_reset(aetherfont_state_t *s);
void aetherfont_event(aetherfont_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
