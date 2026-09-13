#ifndef AETHER_AETHERAWARENESS_H
#define AETHER_AETHERAWARENESS_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherawareness_state { bool enabled; f32 value; u32 events; char text[128]; } aetherawareness_state_t;
void aetherawareness_init(aetherawareness_state_t *s);
void aetherawareness_update(aetherawareness_state_t *s, f32 dt);
void aetherawareness_reset(aetherawareness_state_t *s);
void aetherawareness_event(aetherawareness_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
