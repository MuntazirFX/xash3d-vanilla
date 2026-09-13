#ifndef AETHER_AETHERWEAPONWORLD_H
#define AETHER_AETHERWEAPONWORLD_H
#include "AetherWeapon.h"
#ifdef __cplusplus
extern "C" {
#endif
void aetherweaponworld_init(aether_weapon_t *w);
bool aetherweaponworld_update(aether_weapon_t *w, f32 dt, bool trigger);
#ifdef __cplusplus
}
#endif
#endif
