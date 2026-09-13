#include "AetherBulletHoles.h"
#include <string.h>
void aetherbulletholes_init(aetherbulletholes_state_t *s) { if (s) memset(s, 0, sizeof *s); }
void aetherbulletholes_spawn(aetherbulletholes_state_t *s, aether_vec3_t pos, aether_vec3_t normal) {
    if (!s) return;
    u32 slot = s->next_slot;
    s->holes[slot].position = pos;
    s->holes[slot].normal = normal;
    s->next_slot = (s->next_slot + 1) % AETHER_BULLETHOLES_MAX; /* ring buffer, permanent decals */
    if (s->count < AETHER_BULLETHOLES_MAX) s->count++;
}
