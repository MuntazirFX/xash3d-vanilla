#ifndef AETHER_AETHERWEAPONVIEW_H
#define AETHER_AETHERWEAPONVIEW_H
#include "AetherWeapon.h"
#ifdef __cplusplus
extern "C" {
#endif
void aetherweaponview_init(aether_weapon_t *w);
bool aetherweaponview_update(aether_weapon_t *w, f32 dt, bool trigger);
#ifdef __cplusplus
}
#endif
#endif
