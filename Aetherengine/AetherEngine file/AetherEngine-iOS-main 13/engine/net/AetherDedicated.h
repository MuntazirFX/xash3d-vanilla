#ifndef AETHER_AETHERDEDICATED_H
#define AETHER_AETHERDEDICATED_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherdedicated_state { bool enabled; f32 value; u32 events; char text[128]; } aetherdedicated_state_t;
void aetherdedicated_init(aetherdedicated_state_t *s);
void aetherdedicated_update(aetherdedicated_state_t *s, f32 dt);
void aetherdedicated_reset(aetherdedicated_state_t *s);
void aetherdedicated_event(aetherdedicated_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
