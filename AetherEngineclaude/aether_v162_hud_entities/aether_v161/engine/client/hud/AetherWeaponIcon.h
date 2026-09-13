#ifndef AETHER_WEAPONICON_H
#define AETHER_WEAPONICON_H
#include "../../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
/* Maps a weapon id (matches aether_weapon_id_t values 0-14) to a stable icon
 * slot index the renderer can use to look up its sprite in an atlas. */
typedef struct aetherweaponicon_state {
    u32  weapon_id;
    i32  icon_slot;    /* -1 if unarmed/unknown */
    bool selected;      /* true while this weapon's icon should be highlighted */
} aetherweaponicon_state_t;
void aetherweaponicon_init(aetherweaponicon_state_t *s);
void aetherweaponicon_set(aetherweaponicon_state_t *s, u32 weapon_id, bool selected);
#ifdef __cplusplus
}
#endif
#endif
