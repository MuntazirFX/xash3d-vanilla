#ifndef AETHER_AETHERAMMO_H
#define AETHER_AETHERAMMO_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherammo_state { bool enabled; f32 value; u32 events; char text[128]; } aetherammo_state_t;
void aetherammo_init(aetherammo_state_t *s);
void aetherammo_update(aetherammo_state_t *s, f32 dt);
void aetherammo_reset(aetherammo_state_t *s);
void aetherammo_event(aetherammo_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
