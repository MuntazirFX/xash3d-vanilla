#ifndef AETHER_AETHERFUNCTRAIN_H
#define AETHER_AETHERFUNCTRAIN_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherfunctrain_state { bool enabled; f32 value; u32 events; char text[128]; } aetherfunctrain_state_t;
void aetherfunctrain_init(aetherfunctrain_state_t *s);
void aetherfunctrain_update(aetherfunctrain_state_t *s, f32 dt);
void aetherfunctrain_reset(aetherfunctrain_state_t *s);
void aetherfunctrain_event(aetherfunctrain_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
