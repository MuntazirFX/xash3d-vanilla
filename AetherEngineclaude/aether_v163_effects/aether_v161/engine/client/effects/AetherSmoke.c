#include "AetherSmoke.h"
#include <string.h>
void aethersmoke_init(aethersmoke_state_t *s) { if (s) memset(s, 0, sizeof *s); }
void aethersmoke_spawn(aethersmoke_state_t *s, aether_vec3_t pos) {
    if (!s) return;
    u32 slot = s->count < AETHER_SMOKE_MAX ? s->count++ : 0;
    s->puffs[slot].position = pos;
    s->puffs[slot].size = 8.0f;
    s->puffs[slot].max_life = 3.0f;
    s->puffs[slot].life = 3.0f;
}
void aethersmoke_update(aethersmoke_state_t *s, f32 dt) {
    if (!s) return;
    u32 write = 0;
    for (u32 i = 0; i < s->count; i++) {
        s->puffs[i].life -= dt;
        if (s->puffs[i].life <= 0) continue;
        s->puffs[i].position.z += 20.0f * dt; /* rises */
        s->puffs[i].size += 15.0f * dt;        /* expands as it rises */
        s->puffs[write++] = s->puffs[i];
    }
    s->count = write;
}
f32 aethersmoke_alpha(const aether_smoke_puff_t *puff) {
    if (!puff || puff->max_life <= 0) return 0;
    f32 t = puff->life / puff->max_life;
    return t < 0 ? 0 : (t > 1 ? 1 : t);
}
