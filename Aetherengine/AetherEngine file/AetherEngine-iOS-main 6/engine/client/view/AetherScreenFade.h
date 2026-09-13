#ifndef AETHER_AETHERSCREENFADE_H
#define AETHER_AETHERSCREENFADE_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherscreenfade_state { bool enabled; f32 value; u32 events; char text[128]; } aetherscreenfade_state_t;
void aetherscreenfade_init(aetherscreenfade_state_t *s);
void aetherscreenfade_update(aetherscreenfade_state_t *s, f32 dt);
void aetherscreenfade_reset(aetherscreenfade_state_t *s);
void aetherscreenfade_event(aetherscreenfade_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
