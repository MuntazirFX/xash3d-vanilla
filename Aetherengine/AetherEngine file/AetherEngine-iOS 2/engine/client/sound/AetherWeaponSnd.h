#ifndef AETHER_AETHERWEAPONSND_H
#define AETHER_AETHERWEAPONSND_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherweaponsnd_state { bool enabled; f32 value; u32 events; char text[128]; } aetherweaponsnd_state_t;
void aetherweaponsnd_init(aetherweaponsnd_state_t *s);
void aetherweaponsnd_update(aetherweaponsnd_state_t *s, f32 dt);
void aetherweaponsnd_reset(aetherweaponsnd_state_t *s);
void aetherweaponsnd_event(aetherweaponsnd_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
