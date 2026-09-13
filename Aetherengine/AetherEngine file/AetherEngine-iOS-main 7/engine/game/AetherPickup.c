#include "AetherPickup.h"
#include <string.h>

void aether_pickup_init(aether_pickup_t *p, u32 id, const char *classname,
                        aether_vec3_t position, aether_pickup_type_t type,
                        aether_weapon_id_t weapon_id, const char *ammo_name,
                        i32 amount, i32 max_amount) {
    if (!p) return;
    memset(p, 0, sizeof *p);
    p->id = id;
    p->position = position;
    p->type = type;
    p->weapon_id = weapon_id;
    p->amount = amount;
    p->max_amount = max_amount;
    p->active = true;
    if (classname) { strncpy(p->classname, classname, 63); p->classname[63] = 0; }
    if (ammo_name) { strncpy(p->ammo_name, ammo_name, 31); p->ammo_name[31] = 0; }
}

bool aether_pickup_collect(aether_pickup_t *p,
                           aether_player_health_t *health,
                           aether_player_inventory_t *inventory) {
    if (!p || !p->active) return false;
    bool collected = false;
    switch (p->type) {
        case AETHER_PICKUP_WEAPON:
            collected = inventory && aether_player_inventory_add_weapon(inventory, (u32)p->weapon_id);
            break;
        case AETHER_PICKUP_AMMO:
            collected = inventory && aether_player_inventory_add_ammo(
                inventory, p->ammo_name, p->amount, p->max_amount);
            break;
        case AETHER_PICKUP_HEALTH:
            if (health && health->health < health->max_health) {
                f32 before = health->health;
                aether_player_health_heal(health, (f32)p->amount);
                collected = health->health > before;
            }
            break;
        case AETHER_PICKUP_ARMOR:
            if (health && health->armor < health->max_armor) {
                f32 before = health->armor;
                aether_player_health_add_armor(health, (f32)p->amount);
                collected = health->armor > before;
            }
            break;
        case AETHER_PICKUP_SUIT:
            collected = inventory != NULL && aether_player_inventory_add_ammo(
                inventory, "suit", p->amount, p->max_amount);
            break;
        default: break;
    }
    if (collected) p->active = false;
    return collected;
}
