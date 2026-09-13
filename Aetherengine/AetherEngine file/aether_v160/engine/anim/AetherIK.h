#ifndef AETHER_AETHERIK_H
#define AETHER_AETHERIK_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherik_state { bool enabled; f32 value; u32 events; char text[128]; } aetherik_state_t;
void aetherik_init(aetherik_state_t *s);
void aetherik_update(aetherik_state_t *s, f32 dt);
void aetherik_reset(aetherik_state_t *s);
void aetherik_event(aetherik_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
