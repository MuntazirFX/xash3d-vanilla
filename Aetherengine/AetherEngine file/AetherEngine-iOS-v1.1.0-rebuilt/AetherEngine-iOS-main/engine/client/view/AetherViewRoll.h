#ifndef AETHER_AETHERVIEWROLL_H
#define AETHER_AETHERVIEWROLL_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherviewroll_state { bool enabled; f32 value; u32 events; char text[128]; } aetherviewroll_state_t;
void aetherviewroll_init(aetherviewroll_state_t *s);
void aetherviewroll_update(aetherviewroll_state_t *s, f32 dt);
void aetherviewroll_reset(aetherviewroll_state_t *s);
void aetherviewroll_event(aetherviewroll_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
