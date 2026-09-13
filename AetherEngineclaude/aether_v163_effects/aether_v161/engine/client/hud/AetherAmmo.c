#include "AetherAmmo.h"
#include <string.h>
void aetherammo_init(aetherammo_state_t *s) { if (s) memset(s, 0, sizeof *s); }
void aetherammo_set(aetherammo_state_t *s, i32 clip, i32 reserve, bool infinite) {
    if (!s) return;
    s->clip = clip; s->reserve = reserve; s->infinite = infinite;
    s->clip_empty  = !infinite && clip <= 0 && reserve > 0;
    s->out_of_ammo = !infinite && clip <= 0 && reserve <= 0;
}
