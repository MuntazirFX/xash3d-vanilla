#ifndef AETHER_AETHERSCROLL_H
#define AETHER_AETHERSCROLL_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherscroll_state { bool enabled; f32 value; u32 events; char text[128]; } aetherscroll_state_t;
void aetherscroll_init(aetherscroll_state_t *s);
void aetherscroll_update(aetherscroll_state_t *s, f32 dt);
void aetherscroll_reset(aetherscroll_state_t *s);
void aetherscroll_event(aetherscroll_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
