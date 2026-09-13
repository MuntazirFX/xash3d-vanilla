#ifndef AETHER_BATTERY_H
#define AETHER_BATTERY_H
#include "../../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherbattery_state {
    f32  charge, max_charge;
    bool low;             /* <= 20%, HUD should warn */
    bool flashlight_on;
} aetherbattery_state_t;
void aetherbattery_init(aetherbattery_state_t *s);
void aetherbattery_set_flashlight(aetherbattery_state_t *s, bool on);
/* Drains while flashlight is on, recharges slowly (like suit recharge stations)
 * are handled by aetherbattery_recharge separately. */
void aetherbattery_update(aetherbattery_state_t *s, f32 dt);
void aetherbattery_recharge(aetherbattery_state_t *s, f32 amount);
#ifdef __cplusplus
}
#endif
#endif
