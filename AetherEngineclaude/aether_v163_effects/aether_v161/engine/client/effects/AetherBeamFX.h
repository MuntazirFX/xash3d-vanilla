#ifndef AETHER_BEAMFX_H
#define AETHER_BEAMFX_H
#include "../../core/AetherCore.h"
#include "../../core/AetherMath.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherbeamfx_state {
    aether_vec3_t start, end;
    f32 width;
    f32 life;
    bool active;
    bool continuous;  /* true = stays on until explicitly stopped (egon/tripmine trip-beam) */
} aetherbeamfx_state_t;
void aetherbeamfx_init(aetherbeamfx_state_t *s);
/* duration <= 0 means continuous (caller must call aetherbeamfx_stop explicitly). */
void aetherbeamfx_fire(aetherbeamfx_state_t *s, aether_vec3_t start, aether_vec3_t end, f32 width, f32 duration);
void aetherbeamfx_retarget(aetherbeamfx_state_t *s, aether_vec3_t start, aether_vec3_t end); /* for continuous beams that track aim */
void aetherbeamfx_stop(aetherbeamfx_state_t *s);
void aetherbeamfx_update(aetherbeamfx_state_t *s, f32 dt);
#ifdef __cplusplus
}
#endif
#endif
