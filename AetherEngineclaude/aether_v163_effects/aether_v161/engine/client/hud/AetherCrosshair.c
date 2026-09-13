#include "AetherCrosshair.h"
#include <string.h>
void aethercrosshair_init(aethercrosshair_state_t *s) {
    if (!s) return;
    memset(s, 0, sizeof *s);
    s->style = AETHER_CROSSHAIR_CROSS;
    s->base_gap_px = 4.0f;
}
void aethercrosshair_update(aethercrosshair_state_t *s, bool is_melee, f32 spread) {
    if (!s) return;
    s->style = is_melee ? AETHER_CROSSHAIR_NONE : AETHER_CROSSHAIR_CROSS;
    /* spread is a small angular value (radians-ish, weapon-defined); scale it
     * into a visible pixel gap so shotguns visibly widen the reticle. */
    s->gap_px = s->base_gap_px + (spread > 0 ? spread * 200.0f : 0.0f);
}
