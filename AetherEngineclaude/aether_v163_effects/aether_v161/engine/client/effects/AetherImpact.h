#ifndef AETHER_IMPACT_H
#define AETHER_IMPACT_H
#include "../../core/AetherCore.h"
#include "../../core/AetherMath.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef enum {
    AETHER_SURFACE_CONCRETE = 0,
    AETHER_SURFACE_METAL,
    AETHER_SURFACE_WOOD,
    AETHER_SURFACE_FLESH,
    AETHER_SURFACE_WATER
} aether_surface_t;
typedef enum {
    AETHER_IMPACTFX_DUST = 0,
    AETHER_IMPACTFX_SPARKS,
    AETHER_IMPACTFX_SPLINTERS,
    AETHER_IMPACTFX_BLOOD,
    AETHER_IMPACTFX_SPLASH
} aether_impact_fx_kind_t;
typedef struct aetherimpact_state {
    aether_vec3_t position, normal;
    aether_surface_t surface;
    aether_impact_fx_kind_t fx_kind; /* derived from surface, tells caller which effect module to spawn */
    bool leaves_decal;                /* false for water/flesh — no permanent bullethole */
} aetherimpact_state_t;
void aetherimpact_init(aetherimpact_state_t *s);
void aetherimpact_resolve(aetherimpact_state_t *s, aether_vec3_t position, aether_vec3_t normal, aether_surface_t surface);
#ifdef __cplusplus
}
#endif
#endif
