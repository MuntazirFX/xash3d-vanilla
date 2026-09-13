#ifndef AETHER_WEAPONSELECT_H
#define AETHER_WEAPONSELECT_H
#include "../../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
#define AETHER_WEAPON_SLOT_COUNT 15  /* matches aether_weapon_id_t 0..14 */
typedef struct aetherweaponselect_state {
    bool owned[AETHER_WEAPON_SLOT_COUNT];
    i32  current;      /* currently selected weapon id, -1 if none */
    bool open;          /* true while the selection wheel/list is on screen */
} aetherweaponselect_state_t;
void aetherweaponselect_init(aetherweaponselect_state_t *s);
void aetherweaponselect_set_owned(aetherweaponselect_state_t *s, i32 weapon_id, bool owned);
void aetherweaponselect_open(aetherweaponselect_state_t *s);
/* Moves current to the next/previous owned weapon, wrapping around. No-op if
 * fewer than 2 weapons are owned. */
void aetherweaponselect_cycle(aetherweaponselect_state_t *s, bool forward);
void aetherweaponselect_confirm(aetherweaponselect_state_t *s); /* closes the wheel */
#ifdef __cplusplus
}
#endif
#endif
