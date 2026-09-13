#ifndef AETHER_AETHEROCCLUSION_H
#define AETHER_AETHEROCCLUSION_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherocclusion_state { bool enabled; f32 value; u32 events; char text[128]; } aetherocclusion_state_t;
void aetherocclusion_init(aetherocclusion_state_t *s);
void aetherocclusion_update(aetherocclusion_state_t *s, f32 dt);
void aetherocclusion_reset(aetherocclusion_state_t *s);
void aetherocclusion_event(aetherocclusion_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
