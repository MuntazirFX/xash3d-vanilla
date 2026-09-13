#ifndef AETHER_AETHERGAUSS_H
#define AETHER_AETHERGAUSS_H
#include "AetherWeapon.h"
#ifdef __cplusplus
extern "C" {
#endif
void aethergauss_init(aether_weapon_t *w);
bool aethergauss_update(aether_weapon_t *w, f32 dt, bool trigger);
#ifdef __cplusplus
}
#endif
#endif
