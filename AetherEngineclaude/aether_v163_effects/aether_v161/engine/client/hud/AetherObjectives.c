#include "AetherObjectives.h"
#include <string.h>
void aetherobjectives_init(aetherobjectives_state_t *s) { if (s) memset(s, 0, sizeof *s); }
i32 aetherobjectives_add(aetherobjectives_state_t *s, const char *text) {
    if (!s || s->count >= AETHER_OBJECTIVES_MAX) return -1;
    u32 i = s->count++;
    strncpy(s->items[i].text, text ? text : "", sizeof(s->items[i].text) - 1);
    s->items[i].complete = false;
    return (i32)i;
}
void aetherobjectives_complete(aetherobjectives_state_t *s, i32 index) {
    if (!s || index < 0 || (u32)index >= s->count) return;
    s->items[index].complete = true;
}
u32 aetherobjectives_remaining(const aetherobjectives_state_t *s) {
    if (!s) return 0;
    u32 n = 0;
    for (u32 i = 0; i < s->count; i++) if (!s->items[i].complete) n++;
    return n;
}
