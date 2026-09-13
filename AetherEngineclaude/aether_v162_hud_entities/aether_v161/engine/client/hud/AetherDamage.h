#ifndef AETHER_DAMAGE_H
#define AETHER_DAMAGE_H
#include "../../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
#define AETHER_DAMAGE_MAX_INDICATORS 8
typedef struct {
    f32 angle_deg;   /* direction of the hit relative to player facing, 0 = front */
    f32 life;        /* seconds remaining before this indicator fades out */
} aether_damage_indicator_t;
typedef struct aetherdamage_state {
    aether_damage_indicator_t indicators[AETHER_DAMAGE_MAX_INDICATORS];
    u32 count;
    f32 flash;        /* overall red-screen flash intensity, 0..1 */
} aetherdamage_state_t;
void aetherdamage_init(aetherdamage_state_t *s);
/* Register a hit coming from angle_deg relative to the player's forward vector. */
void aetherdamage_register(aetherdamage_state_t *s, f32 angle_deg, f32 amount);
void aetherdamage_update(aetherdamage_state_t *s, f32 dt);
#ifdef __cplusplus
}
#endif
#endif
