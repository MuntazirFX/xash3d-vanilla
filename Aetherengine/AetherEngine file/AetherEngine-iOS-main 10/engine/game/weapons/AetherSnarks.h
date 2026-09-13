#ifndef AETHER_AETHERSNARKS_H
#define AETHER_AETHERSNARKS_H
#include "AetherWeapon.h"
#ifdef __cplusplus
extern "C" {
#endif
void aethersnarks_init(aether_weapon_t *w);
bool aethersnarks_update(aether_weapon_t *w, f32 dt, bool trigger);
#ifdef __cplusplus
}
#endif
#endif
