#ifndef AETHER_AETHERBONES_H
#define AETHER_AETHERBONES_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherbones_state { bool enabled; f32 value; u32 events; char text[128]; } aetherbones_state_t;
void aetherbones_init(aetherbones_state_t *s);
void aetherbones_update(aetherbones_state_t *s, f32 dt);
void aetherbones_reset(aetherbones_state_t *s);
void aetherbones_event(aetherbones_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
