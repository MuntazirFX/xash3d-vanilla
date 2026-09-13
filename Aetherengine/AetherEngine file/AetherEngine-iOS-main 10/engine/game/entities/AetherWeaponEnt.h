#ifndef AETHER_AETHERWEAPONENT_H
#define AETHER_AETHERWEAPONENT_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherweaponent_state { bool enabled; f32 value; u32 events; char text[128]; } aetherweaponent_state_t;
void aetherweaponent_init(aetherweaponent_state_t *s);
void aetherweaponent_update(aetherweaponent_state_t *s, f32 dt);
void aetherweaponent_reset(aetherweaponent_state_t *s);
void aetherweaponent_event(aetherweaponent_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
