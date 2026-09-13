#ifndef AETHER_HEALTH_H
#define AETHER_HEALTH_H
#include "../../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherhealth_state {
    i32  display_value;   /* rounded HP for on-screen digits */
    bool low_health;      /* true when <= 20% of max, HUD should pulse red */
    bool critical;        /* true when <= 10% of max, faster pulse */
    f32  pulse_phase;     /* 0..1 sine phase for pulsing alpha, driven by update() */
} aetherhealth_state_t;
void aetherhealth_init(aetherhealth_state_t *s);
void aetherhealth_set(aetherhealth_state_t *s, f32 health, f32 max_health);
void aetherhealth_update(aetherhealth_state_t *s, f32 dt);
f32  aetherhealth_pulse_alpha(const aetherhealth_state_t *s); /* 0.3..1.0 for red flash */
#ifdef __cplusplus
}
#endif
#endif
