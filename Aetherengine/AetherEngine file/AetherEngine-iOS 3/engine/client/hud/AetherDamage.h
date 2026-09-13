#ifndef AETHER_AETHERDAMAGE_H
#define AETHER_AETHERDAMAGE_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherdamage_state { bool enabled; f32 value; u32 events; char text[128]; } aetherdamage_state_t;
void aetherdamage_init(aetherdamage_state_t *s);
void aetherdamage_update(aetherdamage_state_t *s, f32 dt);
void aetherdamage_reset(aetherdamage_state_t *s);
void aetherdamage_event(aetherdamage_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
