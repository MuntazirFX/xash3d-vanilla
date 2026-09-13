#ifndef AETHER_AETHERTRIGGER_H
#define AETHER_AETHERTRIGGER_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethertrigger_state { bool enabled; f32 value; u32 events; char text[128]; } aethertrigger_state_t;
void aethertrigger_init(aethertrigger_state_t *s);
void aethertrigger_update(aethertrigger_state_t *s, f32 dt);
void aethertrigger_reset(aethertrigger_state_t *s);
void aethertrigger_event(aethertrigger_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
