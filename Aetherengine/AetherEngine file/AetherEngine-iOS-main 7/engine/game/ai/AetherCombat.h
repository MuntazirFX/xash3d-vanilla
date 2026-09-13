#ifndef AETHER_AETHERCOMBAT_H
#define AETHER_AETHERCOMBAT_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethercombat_state { bool enabled; f32 value; u32 events; char text[128]; } aethercombat_state_t;
void aethercombat_init(aethercombat_state_t *s);
void aethercombat_update(aethercombat_state_t *s, f32 dt);
void aethercombat_reset(aethercombat_state_t *s);
void aethercombat_event(aethercombat_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
