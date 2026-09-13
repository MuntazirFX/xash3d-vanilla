#ifndef AETHER_AETHERAI_H
#define AETHER_AETHERAI_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherai_state { bool enabled; f32 value; u32 events; char text[128]; } aetherai_state_t;
void aetherai_init(aetherai_state_t *s);
void aetherai_update(aetherai_state_t *s, f32 dt);
void aetherai_reset(aetherai_state_t *s);
void aetherai_event(aetherai_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
