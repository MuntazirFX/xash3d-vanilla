#ifndef AETHER_PLAYER_HEALTH_H
#define AETHER_PLAYER_HEALTH_H
#include "../../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aether_player_health { f32 health, max_health, armor, max_armor; bool alive; } aether_player_health_t;
void aether_player_health_init(aether_player_health_t *h);
void aether_player_health_set(aether_player_health_t *h, f32 health, f32 armor);
f32 aether_player_health_apply_damage(aether_player_health_t *h, f32 damage, f32 armor_ratio);
void aether_player_health_heal(aether_player_health_t *h, f32 amount);
void aether_player_health_add_armor(aether_player_health_t *h, f32 amount);
bool aether_player_health_alive(const aether_player_health_t *h);
#ifdef __cplusplus
}
#endif
#endif
