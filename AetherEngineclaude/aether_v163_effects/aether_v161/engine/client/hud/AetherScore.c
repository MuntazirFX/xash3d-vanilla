#include "AetherScore.h"
#include <string.h>
static void recompute_(aetherscore_state_t *s) {
    s->kd_ratio = s->deaths > 0 ? (f32)s->kills / (f32)s->deaths : (f32)s->kills;
}
void aetherscore_init(aetherscore_state_t *s) { if (s) memset(s, 0, sizeof *s); }
void aetherscore_add_kill(aetherscore_state_t *s) { if (!s) return; s->kills++; recompute_(s); }
void aetherscore_add_death(aetherscore_state_t *s) { if (!s) return; s->deaths++; recompute_(s); }
