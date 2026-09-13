#ifndef AETHER_AETHERSAVEWORLD_H
#define AETHER_AETHERSAVEWORLD_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethersaveworld_state { bool enabled; f32 value; u32 events; char text[128]; } aethersaveworld_state_t;
void aethersaveworld_init(aethersaveworld_state_t *s);
void aethersaveworld_update(aethersaveworld_state_t *s, f32 dt);
void aethersaveworld_reset(aethersaveworld_state_t *s);
void aethersaveworld_event(aethersaveworld_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
