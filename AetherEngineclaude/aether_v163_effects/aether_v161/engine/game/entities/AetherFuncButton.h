/* AetherFuncButton.h — func_button: pressable button that fires a target (real implementation).
 * AetherEngine-iOS · Clean-room.
 */
#ifndef AETHER_AETHERFUNCBUTTON_H
#define AETHER_AETHERFUNCBUTTON_H
#include "../../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    AETHER_BUTTON_READY = 0,
    AETHER_BUTTON_PRESSED,
    AETHER_BUTTON_RESETTING
} aether_button_state_t;

typedef struct aetherfuncbutton_state {
    bool   enabled;
    bool   reusable;          /* false = fires once then locks (like a locked door button) */
    f32    reset_delay;       /* seconds pressed-in before popping back out */
    f32    timer;
    aether_button_state_t state;
    u32    events;            /* total press count */
    char   target[32];        /* entity to fire on press (e.g. a func_door targetname) */
} aetherfuncbutton_state_t;

void aetherfuncbutton_init(aetherfuncbutton_state_t *s, f32 reset_delay, bool reusable);
void aetherfuncbutton_update(aetherfuncbutton_state_t *s, f32 dt);
void aetherfuncbutton_reset(aetherfuncbutton_state_t *s);

/* Called when the player uses/presses the button. Returns true if this press
 * actually fires the target (false if already pressed/locked). */
bool aetherfuncbutton_press(aetherfuncbutton_state_t *s);

#ifdef __cplusplus
}
#endif
#endif
