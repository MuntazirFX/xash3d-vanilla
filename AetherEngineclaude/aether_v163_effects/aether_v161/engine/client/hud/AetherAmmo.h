#ifndef AETHER_AMMO_H
#define AETHER_AMMO_H
#include "../../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherammo_state {
    i32  clip, reserve;
    bool clip_empty;      /* clip == 0, reserve > 0 -> prompt reload */
    bool out_of_ammo;     /* clip == 0 AND reserve == 0 */
    bool infinite;        /* weapon has no reserve concept (e.g. crowbar) */
} aetherammo_state_t;
void aetherammo_init(aetherammo_state_t *s);
void aetherammo_set(aetherammo_state_t *s, i32 clip, i32 reserve, bool infinite);
#ifdef __cplusplus
}
#endif
#endif
