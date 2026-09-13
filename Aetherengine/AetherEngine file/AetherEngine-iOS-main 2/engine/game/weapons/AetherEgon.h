#ifndef AETHER_AETHEREGON_H
#define AETHER_AETHEREGON_H
#include "AetherWeapon.h"
#ifdef __cplusplus
extern "C" {
#endif
void aetheregon_init(aether_weapon_t *w);
bool aetheregon_update(aether_weapon_t *w, f32 dt, bool trigger);
#ifdef __cplusplus
}
#endif
#endif
