#ifndef AETHER_AETHERGRENADE_H
#define AETHER_AETHERGRENADE_H
#include "AetherWeapon.h"
#ifdef __cplusplus
extern "C" {
#endif
void aethergrenade_init(aether_weapon_t *w);
bool aethergrenade_update(aether_weapon_t *w, f32 dt, bool trigger);
#ifdef __cplusplus
}
#endif
#endif
