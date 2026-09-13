#ifndef AETHER_AETHERSAVEENTITY_H
#define AETHER_AETHERSAVEENTITY_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethersaveentity_state { bool enabled; f32 value; u32 events; char text[128]; } aethersaveentity_state_t;
void aethersaveentity_init(aethersaveentity_state_t *s);
void aethersaveentity_update(aethersaveentity_state_t *s, f32 dt);
void aethersaveentity_reset(aethersaveentity_state_t *s);
void aethersaveentity_event(aethersaveentity_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
