#ifndef AETHER_AETHERDROPDOWN_H
#define AETHER_AETHERDROPDOWN_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherdropdown_state { bool enabled; f32 value; u32 events; char text[128]; } aetherdropdown_state_t;
void aetherdropdown_init(aetherdropdown_state_t *s);
void aetherdropdown_update(aetherdropdown_state_t *s, f32 dt);
void aetherdropdown_reset(aetherdropdown_state_t *s);
void aetherdropdown_event(aetherdropdown_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
