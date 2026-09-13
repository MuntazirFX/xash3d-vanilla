#ifndef AETHER_MUZZLEFLASH_H
#define AETHER_MUZZLEFLASH_H
#include "../../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethermuzzleflash_state {
    f32 life;       /* seconds remaining that the flash sprite/light should render */
    f32 duration;    /* full flash duration, scales down for very fast-firing weapons */
} aethermuzzleflash_state_t;
void aethermuzzleflash_init(aethermuzzleflash_state_t *s);
/* weapon_fire_delay: the weapon's own cooldown between shots — flash never
 * outlasts the time until the next shot, so full-auto weapons get short flashes. */
void aethermuzzleflash_trigger(aethermuzzleflash_state_t *s, f32 weapon_fire_delay);
void aethermuzzleflash_update(aethermuzzleflash_state_t *s, f32 dt);
bool aethermuzzleflash_visible(const aethermuzzleflash_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
