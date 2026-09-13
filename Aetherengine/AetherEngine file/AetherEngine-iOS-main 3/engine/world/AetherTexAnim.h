#ifndef AETHER_AETHERTEXANIM_H
#define AETHER_AETHERTEXANIM_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethertexanim_state { bool enabled; f32 value; u32 events; char text[128]; } aethertexanim_state_t;
void aethertexanim_init(aethertexanim_state_t *s);
void aethertexanim_update(aethertexanim_state_t *s, f32 dt);
void aethertexanim_reset(aethertexanim_state_t *s);
void aethertexanim_event(aethertexanim_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
