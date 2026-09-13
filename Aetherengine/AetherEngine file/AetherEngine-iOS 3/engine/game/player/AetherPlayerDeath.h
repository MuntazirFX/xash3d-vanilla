#ifndef AETHER_PLAYER_DEATH_H
#define AETHER_PLAYER_DEATH_H
#include "../../core/AetherCore.h"
#include "../../core/AetherMath.h"
#include "AetherPlayerHealth.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aether_player_death { bool dead; f32 respawn_delay; f32 timer; u32 deaths; } aether_player_death_t;
void aether_player_death_init(aether_player_death_t*d);
void aether_player_death_kill(aether_player_death_t*d);
bool aether_player_death_update(aether_player_death_t*d,f32 dt);
void aether_player_death_respawn(aether_player_death_t*d,aether_player_health_t*h);
#ifdef __cplusplus
}
#endif
#endif
