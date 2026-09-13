#ifndef AETHER_AETHERFUNCWATER_H
#define AETHER_AETHERFUNCWATER_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherfuncwater_state { bool enabled; f32 value; u32 events; char text[128]; } aetherfuncwater_state_t;
void aetherfuncwater_init(aetherfuncwater_state_t *s);
void aetherfuncwater_update(aetherfuncwater_state_t *s, f32 dt);
void aetherfuncwater_reset(aetherfuncwater_state_t *s);
void aetherfuncwater_event(aetherfuncwater_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
