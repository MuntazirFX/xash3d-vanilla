#include "AetherBeamFX.h"
#include <string.h>
void aetherbeamfx_init(aetherbeamfx_state_t *s) { if (s) memset(s, 0, sizeof *s); }
void aetherbeamfx_fire(aetherbeamfx_state_t *s, aether_vec3_t start, aether_vec3_t end, f32 width, f32 duration) {
    if (!s) return;
    s->start = start; s->end = end;
    s->width = width > 0 ? width : 2.0f;
    s->continuous = duration <= 0;
    s->life = duration;
    s->active = true;
}
void aetherbeamfx_retarget(aetherbeamfx_state_t *s, aether_vec3_t start, aether_vec3_t end) {
    if (!s || !s->active || !s->continuous) return;
    s->start = start; s->end = end;
}
void aetherbeamfx_stop(aetherbeamfx_state_t *s) { if (s) s->active = false; }
void aetherbeamfx_update(aetherbeamfx_state_t *s, f32 dt) {
    if (!s || !s->active || s->continuous) return;
    s->life -= dt;
    if (s->life <= 0) s->active = false;
}
