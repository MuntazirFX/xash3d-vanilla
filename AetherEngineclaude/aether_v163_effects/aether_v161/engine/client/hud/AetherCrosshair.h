#ifndef AETHER_CROSSHAIR_H
#define AETHER_CROSSHAIR_H
#include "../../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef enum {
    AETHER_CROSSHAIR_DOT = 0,
    AETHER_CROSSHAIR_CROSS,
    AETHER_CROSSHAIR_CIRCLE,
    AETHER_CROSSHAIR_NONE   /* melee weapons: no ranged reticle */
} aether_crosshair_style_t;
typedef struct aethercrosshair_state {
    aether_crosshair_style_t style;
    f32 gap_px;         /* current visual gap between crosshair lines, grows with spread */
    f32 base_gap_px;
} aethercrosshair_state_t;
void aethercrosshair_init(aethercrosshair_state_t *s);
/* is_melee: true for crowbar-type weapons -> hides the reticle.
 * weapon_spread: the weapon's current spread value (0 = perfectly accurate). */
void aethercrosshair_update(aethercrosshair_state_t *s, bool is_melee, f32 weapon_spread);
#ifdef __cplusplus
}
#endif
#endif
