#include "AetherWeaponSelect.h"
#include <string.h>
void aetherweaponselect_init(aetherweaponselect_state_t *s) {
    if (!s) return;
    memset(s, 0, sizeof *s);
    s->current = -1;
}
void aetherweaponselect_set_owned(aetherweaponselect_state_t *s, i32 id, bool owned) {
    if (!s || id < 0 || id >= AETHER_WEAPON_SLOT_COUNT) return;
    s->owned[id] = owned;
    if (s->current < 0 && owned) s->current = id;
    if (!owned && s->current == id) s->current = -1;
}
void aetherweaponselect_open(aetherweaponselect_state_t *s) { if (s) s->open = true; }
void aetherweaponselect_confirm(aetherweaponselect_state_t *s) { if (s) s->open = false; }
void aetherweaponselect_cycle(aetherweaponselect_state_t *s, bool forward) {
    if (!s) return;
    i32 start = s->current < 0 ? 0 : s->current;
    for (i32 step = 1; step <= AETHER_WEAPON_SLOT_COUNT; step++) {
        i32 idx = forward
            ? (start + step) % AETHER_WEAPON_SLOT_COUNT
            : (start - step % AETHER_WEAPON_SLOT_COUNT + AETHER_WEAPON_SLOT_COUNT) % AETHER_WEAPON_SLOT_COUNT;
        if (s->owned[idx]) { s->current = idx; return; }
    }
}
