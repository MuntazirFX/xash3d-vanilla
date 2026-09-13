#ifndef AETHER_AETHERWEAPONANIM_H
#define AETHER_AETHERWEAPONANIM_H
#include "AetherWeapon.h"
#ifdef __cplusplus
extern "C" {
#endif
void aether_weapon_anim_init(aether_weapon_t *w);
bool aether_weapon_anim_update(aether_weapon_t *w, f32 dt, bool trigger);
#ifdef __cplusplus
}
#endif
#endif
