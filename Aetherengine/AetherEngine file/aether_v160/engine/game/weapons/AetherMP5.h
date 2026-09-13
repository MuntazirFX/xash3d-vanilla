#ifndef AETHER_AETHERMP5_H
#define AETHER_AETHERMP5_H
#include "AetherWeapon.h"
#ifdef __cplusplus
extern "C" {
#endif
void aethermp5_init(aether_weapon_t *w);
bool aethermp5_update(aether_weapon_t *w, f32 dt, bool trigger);
#ifdef __cplusplus
}
#endif
#endif
