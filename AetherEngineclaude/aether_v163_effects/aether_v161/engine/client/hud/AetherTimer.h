#ifndef AETHER_TIMER_H
#define AETHER_TIMER_H
#include "../../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethertimer_state {
    f32  seconds_remaining;  /* counts down; for count-up timers use a negative duration */
    bool counting_up;
    f32  elapsed;
    bool expired;
    i32  minutes_display, seconds_display; /* MM:SS split, recomputed each update */
} aethertimer_state_t;
void aethertimer_init(aethertimer_state_t *s);
void aethertimer_start_countdown(aethertimer_state_t *s, f32 seconds);
void aethertimer_start_countup(aethertimer_state_t *s);
void aethertimer_update(aethertimer_state_t *s, f32 dt);
#ifdef __cplusplus
}
#endif
#endif
