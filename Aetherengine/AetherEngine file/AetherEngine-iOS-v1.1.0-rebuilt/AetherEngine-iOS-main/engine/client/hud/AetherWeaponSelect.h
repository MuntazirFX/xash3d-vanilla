#ifndef AETHER_AETHERWEAPONSELECT_H
#define AETHER_AETHERWEAPONSELECT_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherweaponselect_state { bool enabled; f32 value; u32 events; char text[128]; } aetherweaponselect_state_t;
void aetherweaponselect_init(aetherweaponselect_state_t *s);
void aetherweaponselect_update(aetherweaponselect_state_t *s, f32 dt);
void aetherweaponselect_reset(aetherweaponselect_state_t *s);
void aetherweaponselect_event(aetherweaponselect_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
