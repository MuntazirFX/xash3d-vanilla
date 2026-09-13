#ifndef AETHER_AETHERAUDIOOPTS_H
#define AETHER_AETHERAUDIOOPTS_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetheraudioopts_state { bool enabled; f32 value; u32 events; char text[128]; } aetheraudioopts_state_t;
void aetheraudioopts_init(aetheraudioopts_state_t *s);
void aetheraudioopts_update(aetheraudioopts_state_t *s, f32 dt);
void aetheraudioopts_reset(aetheraudioopts_state_t *s);
void aetheraudioopts_event(aetheraudioopts_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
