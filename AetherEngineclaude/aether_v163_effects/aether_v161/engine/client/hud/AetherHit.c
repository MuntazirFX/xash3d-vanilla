#include "AetherHit.h"
#include <string.h>
void aetherhit_init(aetherhit_state_t *s) { if (s) memset(s, 0, sizeof *s); }
void aetherhit_register(aetherhit_state_t *s, bool killed_target) {
    if (!s) return;
    s->marker_life = killed_target ? 0.6f : 0.2f;
    s->was_kill = killed_target;
}
void aetherhit_update(aetherhit_state_t *s, f32 dt) {
    if (!s) return;
    if (s->marker_life > 0) s->marker_life -= dt;
    if (s->marker_life < 0) s->marker_life = 0;
}
bool aetherhit_visible(const aetherhit_state_t *s) { return s && s->marker_life > 0; }
