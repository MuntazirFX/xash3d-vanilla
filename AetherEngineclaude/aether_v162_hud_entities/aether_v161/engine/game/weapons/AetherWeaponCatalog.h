#ifndef AETHER_WEAPON_CATALOG_H
#define AETHER_WEAPON_CATALOG_H
#include "AetherWeapon.h"
#ifdef __cplusplus
extern "C" {
#endif
void aether_weapon_catalog_init(aether_weapon_t weapons[15]);
const aether_weapon_t *aether_weapon_catalog_get(const aether_weapon_t weapons[15], aether_weapon_id_t id);
#ifdef __cplusplus
}
#endif
#endif
