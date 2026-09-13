#ifndef AETHER_AETHERFOG_H
#define AETHER_AETHERFOG_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherfog_state { bool enabled; f32 value; u32 events; char text[128]; } aetherfog_state_t;
void aetherfog_init(aetherfog_state_t *s);
void aetherfog_update(aetherfog_state_t *s, f32 dt);
void aetherfog_reset(aetherfog_state_t *s);
void aetherfog_event(aetherfog_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
