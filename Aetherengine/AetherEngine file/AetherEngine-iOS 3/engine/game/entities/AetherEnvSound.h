#ifndef AETHER_AETHERENVSOUND_H
#define AETHER_AETHERENVSOUND_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherenvsound_state { bool enabled; f32 value; u32 events; char text[128]; } aetherenvsound_state_t;
void aetherenvsound_init(aetherenvsound_state_t *s);
void aetherenvsound_update(aetherenvsound_state_t *s, f32 dt);
void aetherenvsound_reset(aetherenvsound_state_t *s);
void aetherenvsound_event(aetherenvsound_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
