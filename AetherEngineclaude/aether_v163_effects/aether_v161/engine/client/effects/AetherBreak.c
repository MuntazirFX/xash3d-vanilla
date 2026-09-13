#include "AetherBreak.h"
#include <string.h>
void aetherbreak_init(aetherbreak_state_t *s) { if (s) memset(s, 0, sizeof *s); }
void aetherbreak_shatter(aetherbreak_state_t *s, aether_vec3_t pos, aether_break_material_t mat) {
    if (!s) return;
    s->material = mat;
    /* glass shatters into more, lighter pieces than wood/metal chunks */
    u32 piece_count = mat == AETHER_BREAK_GLASS ? AETHER_BREAK_MAX_PIECES
                     : mat == AETHER_BREAK_WOOD  ? 6 : 4;
    s->count = piece_count;
    for (u32 i = 0; i < piece_count; i++) {
        f32 ang = (f32)i / piece_count * 6.2831853f;
        s->pieces[i].position = pos;
        s->pieces[i].velocity.x = (f32)(ang > 3.14f ? -1 : 1) * 90.0f;
        s->pieces[i].velocity.y = (f32)(i % 2 ? -1 : 1) * 90.0f;
        s->pieces[i].velocity.z = 120.0f;
        s->pieces[i].life = mat == AETHER_BREAK_GLASS ? 1.0f : 2.0f;
    }
}
void aetherbreak_update(aetherbreak_state_t *s, f32 dt) {
    if (!s) return;
    u32 write = 0;
    for (u32 i = 0; i < s->count; i++) {
        s->pieces[i].life -= dt;
        if (s->pieces[i].life <= 0) continue;
        s->pieces[i].position.x += s->pieces[i].velocity.x * dt;
        s->pieces[i].position.y += s->pieces[i].velocity.y * dt;
        s->pieces[i].position.z += s->pieces[i].velocity.z * dt;
        s->pieces[i].velocity.z -= 500.0f * dt;
        s->pieces[write++] = s->pieces[i];
    }
    s->count = write;
}
