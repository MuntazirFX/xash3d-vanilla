#ifndef AETHER_PICKUP_H
#define AETHER_PICKUP_H

#include "../core/AetherCore.h"
#include "../core/AetherMath.h"
#include "weapons/AetherWeapon.h"
#include "player/AetherPlayerHealth.h"
#include "player/AetherPlayerInventory.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum aether_pickup_type {
    AETHER_PICKUP_NONE = 0,
    AETHER_PICKUP_WEAPON,
    AETHER_PICKUP_AMMO,
    AETHER_PICKUP_HEALTH,
    AETHER_PICKUP_ARMOR,
    AETHER_PICKUP_SUIT
} aether_pickup_type_t;

typedef struct aether_pickup {
    u32 id;
    char classname[64];
    char ammo_name[32];
    aether_vec3_t position;
    aether_pickup_type_t type;
    aether_weapon_id_t weapon_id;
    i32 amount;
    i32 max_amount;
    bool active;
} aether_pickup_t;

void aether_pickup_init(aether_pickup_t *p, u32 id, const char *classname,
                        aether_vec3_t position, aether_pickup_type_t type,
                        aether_weapon_id_t weapon_id, const char *ammo_name,
                        i32 amount, i32 max_amount);

bool aether_pickup_collect(aether_pickup_t *p,
                           aether_player_health_t *health,
                           aether_player_inventory_t *inventory);

#ifdef __cplusplus
}
#endif
#endif
