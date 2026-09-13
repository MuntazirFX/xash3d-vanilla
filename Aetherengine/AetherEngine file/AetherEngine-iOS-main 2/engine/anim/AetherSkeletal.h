#ifndef AETHER_AETHERSKELETAL_H
#define AETHER_AETHERSKELETAL_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherskeletal_state { bool enabled; f32 value; u32 events; char text[128]; } aetherskeletal_state_t;
void aetherskeletal_init(aetherskeletal_state_t *s);
void aetherskeletal_update(aetherskeletal_state_t *s, f32 dt);
void aetherskeletal_reset(aetherskeletal_state_t *s);
void aetherskeletal_event(aetherskeletal_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
