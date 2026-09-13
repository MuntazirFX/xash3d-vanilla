#ifndef AETHER_AETHERLIGHTNING_H
#define AETHER_AETHERLIGHTNING_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherlightning_state { bool enabled; f32 value; u32 events; char text[128]; } aetherlightning_state_t;
void aetherlightning_init(aetherlightning_state_t *s);
void aetherlightning_update(aetherlightning_state_t *s, f32 dt);
void aetherlightning_reset(aetherlightning_state_t *s);
void aetherlightning_event(aetherlightning_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
