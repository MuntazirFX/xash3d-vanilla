#ifndef AETHER_AETHERBATTERY_H
#define AETHER_AETHERBATTERY_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherbattery_state { bool enabled; f32 value; u32 events; char text[128]; } aetherbattery_state_t;
void aetherbattery_init(aetherbattery_state_t *s);
void aetherbattery_update(aetherbattery_state_t *s, f32 dt);
void aetherbattery_reset(aetherbattery_state_t *s);
void aetherbattery_event(aetherbattery_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
