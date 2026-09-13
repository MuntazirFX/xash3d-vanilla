#ifndef AETHER_AETHERSCOREBOARD_H
#define AETHER_AETHERSCOREBOARD_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherscoreboard_state { bool enabled; f32 value; u32 events; char text[128]; } aetherscoreboard_state_t;
void aetherscoreboard_init(aetherscoreboard_state_t *s);
void aetherscoreboard_update(aetherscoreboard_state_t *s, f32 dt);
void aetherscoreboard_reset(aetherscoreboard_state_t *s);
void aetherscoreboard_event(aetherscoreboard_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
