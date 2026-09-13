#include "AetherFuncButton.h"
#include <string.h>

void aetherfuncbutton_init(aetherfuncbutton_state_t *s, f32 reset_delay, bool reusable) {
    if (!s) return;
    memset(s, 0, sizeof *s);
    s->enabled = true;
    s->reusable = reusable;
    s->reset_delay = reset_delay > 0 ? reset_delay : 1.0f;
    s->state = AETHER_BUTTON_READY;
}

void aetherfuncbutton_reset(aetherfuncbutton_state_t *s) {
    if (!s) return;
    s->state = AETHER_BUTTON_READY;
    s->timer = 0;
}

bool aetherfuncbutton_press(aetherfuncbutton_state_t *s) {
    if (!s || !s->enabled) return false;
    if (s->state != AETHER_BUTTON_READY) return false;
    s->state = AETHER_BUTTON_PRESSED;
    s->timer = 0;
    s->events++;
    if (!s->reusable) s->enabled = false; /* locks out after first use */
    return true;
}

void aetherfuncbutton_update(aetherfuncbutton_state_t *s, f32 dt) {
    if (!s || dt <= 0) return;
    if (s->state == AETHER_BUTTON_PRESSED) {
        s->timer += dt;
        if (s->timer >= s->reset_delay) {
            s->state = s->reusable ? AETHER_BUTTON_READY : AETHER_BUTTON_RESETTING;
        }
    }
}
