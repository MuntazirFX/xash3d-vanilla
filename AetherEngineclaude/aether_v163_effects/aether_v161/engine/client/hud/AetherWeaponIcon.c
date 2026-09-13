#include "AetherWeaponIcon.h"
#include <string.h>
void aetherweaponicon_init(aetherweaponicon_state_t *s) { if (s) { memset(s, 0, sizeof *s); s->icon_slot = -1; } }
void aetherweaponicon_set(aetherweaponicon_state_t *s, u32 weapon_id, bool selected) {
    if (!s) return;
    s->weapon_id = weapon_id;
    /* weapon ids run 0(none)-14(snarks) contiguously, so the id itself is a
     * stable atlas slot; 0 means "no icon". */
    s->icon_slot = (weapon_id >= 1 && weapon_id <= 14) ? (i32)(weapon_id - 1) : -1;
    s->selected = selected;
}
