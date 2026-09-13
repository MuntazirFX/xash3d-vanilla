#ifndef AETHER_AETHERWEAPONICON_H
#define AETHER_AETHERWEAPONICON_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherweaponicon_state { bool enabled; f32 value; u32 events; char text[128]; } aetherweaponicon_state_t;
void aetherweaponicon_init(aetherweaponicon_state_t *s);
void aetherweaponicon_update(aetherweaponicon_state_t *s, f32 dt);
void aetherweaponicon_reset(aetherweaponicon_state_t *s);
void aetherweaponicon_event(aetherweaponicon_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
