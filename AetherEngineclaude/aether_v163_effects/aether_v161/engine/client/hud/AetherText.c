#include "AetherText.h"
#include <string.h>
void aethertext_init(aethertext_state_t *s) { if (s) memset(s, 0, sizeof *s); }
void aethertext_push(aethertext_state_t *s, const char *message, f32 seconds) {
    if (!s) return;
    if (s->count >= AETHER_TEXT_QUEUE_MAX) {
        memmove(&s->queue[0], &s->queue[1], sizeof(s->queue[0]) * (AETHER_TEXT_QUEUE_MAX - 1));
        s->count--;
    }
    aether_text_entry_t *e = &s->queue[s->count++];
    strncpy(e->message, message ? message : "", sizeof(e->message) - 1);
    e->time_left = seconds > 0 ? seconds : 3.0f;
}
void aethertext_update(aethertext_state_t *s, f32 dt) {
    if (!s || dt <= 0) return;
    u32 write = 0;
    for (u32 i = 0; i < s->count; i++) {
        s->queue[i].time_left -= dt;
        if (s->queue[i].time_left > 0) s->queue[write++] = s->queue[i];
    }
    s->count = write;
}
