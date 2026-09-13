#include "AetherImpact.h"
#include <string.h>
void aetherimpact_init(aetherimpact_state_t *s) { if (s) memset(s, 0, sizeof *s); }
void aetherimpact_resolve(aetherimpact_state_t *s, aether_vec3_t pos, aether_vec3_t normal, aether_surface_t surface) {
    if (!s) return;
    s->position = pos;
    s->normal = normal;
    s->surface = surface;
    switch (surface) {
        case AETHER_SURFACE_METAL:  s->fx_kind = AETHER_IMPACTFX_SPARKS;     s->leaves_decal = true;  break;
        case AETHER_SURFACE_WOOD:   s->fx_kind = AETHER_IMPACTFX_SPLINTERS;  s->leaves_decal = true;  break;
        case AETHER_SURFACE_FLESH:  s->fx_kind = AETHER_IMPACTFX_BLOOD;      s->leaves_decal = false; break;
        case AETHER_SURFACE_WATER:  s->fx_kind = AETHER_IMPACTFX_SPLASH;     s->leaves_decal = false; break;
        case AETHER_SURFACE_CONCRETE:
        default:                    s->fx_kind = AETHER_IMPACTFX_DUST;      s->leaves_decal = true;  break;
    }
}
