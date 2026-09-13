#ifndef AETHER_AETHERANIMEVENT_H
#define AETHER_AETHERANIMEVENT_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetheranimevent_state { bool enabled; f32 value; u32 events; char text[128]; } aetheranimevent_state_t;
void aetheranimevent_init(aetheranimevent_state_t *s);
void aetheranimevent_update(aetheranimevent_state_t *s, f32 dt);
void aetheranimevent_reset(aetheranimevent_state_t *s);
void aetheranimevent_event(aetheranimevent_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
