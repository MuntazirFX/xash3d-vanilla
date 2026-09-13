#include "AetherTimer.h"
#include <string.h>
static void split_(aethertimer_state_t *s, f32 total) {
    if (total < 0) total = 0;
    i32 whole = (i32)total;
    s->minutes_display = whole / 60;
    s->seconds_display = whole % 60;
}
void aethertimer_init(aethertimer_state_t *s) { if (s) memset(s, 0, sizeof *s); }
void aethertimer_start_countdown(aethertimer_state_t *s, f32 seconds) {
    if (!s) return;
    s->counting_up = false;
    s->seconds_remaining = seconds > 0 ? seconds : 0;
    s->expired = false;
    split_(s, s->seconds_remaining);
}
void aethertimer_start_countup(aethertimer_state_t *s) {
    if (!s) return;
    s->counting_up = true;
    s->elapsed = 0;
    s->expired = false;
    split_(s, 0);
}
void aethertimer_update(aethertimer_state_t *s, f32 dt) {
    if (!s || dt <= 0) return;
    if (s->counting_up) {
        s->elapsed += dt;
        split_(s, s->elapsed);
    } else {
        s->seconds_remaining -= dt;
        if (s->seconds_remaining <= 0) { s->seconds_remaining = 0; s->expired = true; }
        split_(s, s->seconds_remaining);
    }
}
