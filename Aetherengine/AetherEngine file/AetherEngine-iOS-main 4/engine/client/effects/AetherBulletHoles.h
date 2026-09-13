#ifndef AETHER_AETHERBULLETHOLES_H
#define AETHER_AETHERBULLETHOLES_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherbulletholes_state { bool enabled; f32 value; u32 events; char text[128]; } aetherbulletholes_state_t;
void aetherbulletholes_init(aetherbulletholes_state_t *s);
void aetherbulletholes_update(aetherbulletholes_state_t *s, f32 dt);
void aetherbulletholes_reset(aetherbulletholes_state_t *s);
void aetherbulletholes_event(aetherbulletholes_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
