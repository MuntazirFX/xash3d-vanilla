#include "AetherArmor.h"
#include <string.h>
void aetherarmor_init(aetherarmor_state_t *s) { if (s) memset(s, 0, sizeof *s); }
void aetherarmor_set(aetherarmor_state_t *s, f32 armor) {
    if (!s) return;
    s->display_value = (i32)(armor + 0.5f);
    s->depleted = armor <= 0.0f;
}
