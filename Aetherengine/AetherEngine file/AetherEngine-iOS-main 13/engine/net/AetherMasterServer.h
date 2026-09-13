#ifndef AETHER_AETHERMASTERSERVER_H
#define AETHER_AETHERMASTERSERVER_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethermasterserver_state { bool enabled; f32 value; u32 events; char text[128]; } aethermasterserver_state_t;
void aethermasterserver_init(aethermasterserver_state_t *s);
void aethermasterserver_update(aethermasterserver_state_t *s, f32 dt);
void aethermasterserver_reset(aethermasterserver_state_t *s);
void aethermasterserver_event(aethermasterserver_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
