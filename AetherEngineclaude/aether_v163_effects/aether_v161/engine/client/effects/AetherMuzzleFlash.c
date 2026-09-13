#include "AetherMuzzleFlash.h"
#include <string.h>
static f32 minf_(f32 a, f32 b) { return a < b ? a : b; }
void aethermuzzleflash_init(aethermuzzleflash_state_t *s) { if (s) memset(s, 0, sizeof *s); }
void aethermuzzleflash_trigger(aethermuzzleflash_state_t *s, f32 fire_delay) {
    if (!s) return;
    s->duration = minf_(0.05f, fire_delay > 0 ? fire_delay * 0.8f : 0.05f);
    s->life = s->duration;
}
void aethermuzzleflash_update(aethermuzzleflash_state_t *s, f32 dt) {
    if (!s) return;
    if (s->life > 0) s->life -= dt;
    if (s->life < 0) s->life = 0;
}
bool aethermuzzleflash_visible(const aethermuzzleflash_state_t *s) { return s && s->life > 0; }
