#ifndef AETHER_AETHERSHOTGUN_H
#define AETHER_AETHERSHOTGUN_H
#include "AetherWeapon.h"
#ifdef __cplusplus
extern "C" {
#endif
void aethershotgun_init(aether_weapon_t *w);
bool aethershotgun_update(aether_weapon_t *w, f32 dt, bool trigger);
#ifdef __cplusplus
}
#endif
#endif
