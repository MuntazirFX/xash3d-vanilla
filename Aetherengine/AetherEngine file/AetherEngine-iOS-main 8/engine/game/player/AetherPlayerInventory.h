#ifndef AETHER_PLAYER_INVENTORY_H
#define AETHER_PLAYER_INVENTORY_H
#include "../../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
#define AETHER_MAX_WEAPONS 32
#define AETHER_MAX_AMMO 32
typedef struct aether_ammo_slot { char name[32]; i32 count; i32 max_count; } aether_ammo_slot_t;
typedef struct aether_player_inventory { u32 weapon_ids[AETHER_MAX_WEAPONS]; u32 weapon_count; i32 current_weapon; aether_ammo_slot_t ammo[AETHER_MAX_AMMO]; u32 ammo_count; } aether_player_inventory_t;
void aether_player_inventory_init(aether_player_inventory_t*i);
bool aether_player_inventory_add_weapon(aether_player_inventory_t*i,u32 id);
bool aether_player_inventory_has_weapon(const aether_player_inventory_t*i,u32 id);
void aether_player_inventory_set_current(aether_player_inventory_t*i,i32 index);
i32 aether_player_inventory_current(const aether_player_inventory_t*i);
bool aether_player_inventory_add_ammo(aether_player_inventory_t*i,const char*name,i32 amount,i32 max_count);
i32 aether_player_inventory_ammo(const aether_player_inventory_t*i,const char*name);
bool aether_player_inventory_use_ammo(aether_player_inventory_t*i,const char*name,i32 amount);
#ifdef __cplusplus
}
#endif
#endif
