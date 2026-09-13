#ifndef AETHER_AETHERFUNCCHARGER_H
#define AETHER_AETHERFUNCCHARGER_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherfunccharger_state { bool enabled; f32 value; u32 events; char text[128]; } aetherfunccharger_state_t;
void aetherfunccharger_init(aetherfunccharger_state_t *s);
void aetherfunccharger_update(aetherfunccharger_state_t *s, f32 dt);
void aetherfunccharger_reset(aetherfunccharger_state_t *s);
void aetherfunccharger_event(aetherfunccharger_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
