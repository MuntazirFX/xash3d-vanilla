#ifndef AETHER_AETHERHIVEHAND_H
#define AETHER_AETHERHIVEHAND_H
#include "AetherWeapon.h"
#ifdef __cplusplus
extern "C" {
#endif
void aetherhivehand_init(aether_weapon_t *w);
bool aetherhivehand_update(aether_weapon_t *w, f32 dt, bool trigger);
#ifdef __cplusplus
}
#endif
#endif
