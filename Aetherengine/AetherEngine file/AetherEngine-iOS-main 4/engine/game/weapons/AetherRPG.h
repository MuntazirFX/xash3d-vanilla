#ifndef AETHER_AETHERRPG_H
#define AETHER_AETHERRPG_H
#include "AetherWeapon.h"
#ifdef __cplusplus
extern "C" {
#endif
void aetherrpg_init(aether_weapon_t *w);
bool aetherrpg_update(aether_weapon_t *w, f32 dt, bool trigger);
#ifdef __cplusplus
}
#endif
#endif
