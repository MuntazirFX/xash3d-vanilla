#ifndef AETHER_AETHERSATCHEL_H
#define AETHER_AETHERSATCHEL_H
#include "AetherWeapon.h"
#ifdef __cplusplus
extern "C" {
#endif
void aethersatchel_init(aether_weapon_t *w);
bool aethersatchel_update(aether_weapon_t *w, f32 dt, bool trigger);
#ifdef __cplusplus
}
#endif
#endif
