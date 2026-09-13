#ifndef AETHER_AETHERVIEWANIM_H
#define AETHER_AETHERVIEWANIM_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherviewanim_state { bool enabled; f32 value; u32 events; char text[128]; } aetherviewanim_state_t;
void aetherviewanim_init(aetherviewanim_state_t *s);
void aetherviewanim_update(aetherviewanim_state_t *s, f32 dt);
void aetherviewanim_reset(aetherviewanim_state_t *s);
void aetherviewanim_event(aetherviewanim_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
