#ifndef AETHER_PLAYER_DAMAGE_H
#define AETHER_PLAYER_DAMAGE_H
#include "AetherPlayerHealth.h"
#include "../../core/AetherMath.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef enum { AETHER_DAMAGE_GENERIC=0, AETHER_DAMAGE_BULLET, AETHER_DAMAGE_MELEE, AETHER_DAMAGE_FALL, AETHER_DAMAGE_FIRE, AETHER_DAMAGE_EXPLOSION, AETHER_DAMAGE_DROWN } aether_damage_type_t;
typedef struct aether_damage { f32 amount; f32 armor_ratio; aether_damage_type_t type; aether_vec3_t origin; aether_vec3_t direction; void *attacker; } aether_damage_t;
f32 aether_player_apply_damage(aether_player_health_t*h,const aether_damage_t*d);
f32 aether_player_fall_damage(f32 speed);
#ifdef __cplusplus
}
#endif
#endif
