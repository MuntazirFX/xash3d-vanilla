#ifndef AETHER_AETHERWEAPONSYNC_H
#define AETHER_AETHERWEAPONSYNC_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherweaponsync_state { bool enabled; f32 value; u32 events; char text[128]; } aetherweaponsync_state_t;
void aetherweaponsync_init(aetherweaponsync_state_t *s);
void aetherweaponsync_update(aetherweaponsync_state_t *s, f32 dt);
void aetherweaponsync_reset(aetherweaponsync_state_t *s);
void aetherweaponsync_event(aetherweaponsync_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
