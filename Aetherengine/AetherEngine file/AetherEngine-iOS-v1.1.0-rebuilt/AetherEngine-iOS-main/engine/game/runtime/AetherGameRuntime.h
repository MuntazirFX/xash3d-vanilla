#ifndef AETHER_GAME_RUNTIME_H
#define AETHER_GAME_RUNTIME_H
#include "../../core/AetherCore.h"
#include "../../core/AetherMath.h"
#include "../../input/AetherInput.h"
#include "../../player/AetherPlayer.h"
#include "../player/AetherPlayerHealth.h"
#include "../player/AetherPlayerDamage.h"
#include "../player/AetherPlayerDeath.h"
#include "../player/AetherPlayerInventory.h"
#include "../weapons/AetherWeapon.h"
#include "../monsters/AetherMonsterBase.h"
#ifdef __cplusplus
extern "C" {
#endif
#define AETHER_RUNTIME_MAX_MONSTERS 128
typedef enum { AETHER_GAME_LOADING=0, AETHER_GAME_RUNNING, AETHER_GAME_PAUSED, AETHER_GAME_DEAD } aether_game_state_t;
typedef struct aether_game_runtime {
    aether_game_state_t state;
    f32 time;
    u64 ticks;
    aether_player_t player;
    aether_player_health_t health;
    aether_player_inventory_t inventory;
    aether_player_death_t death;
    aether_weapon_t weapon;
    aether_monster_t monsters[AETHER_RUNTIME_MAX_MONSTERS];
    u32 monster_count;
    aether_vec3_t spawn_position;
    f32 spawn_yaw;
} aether_game_runtime_t;
void aether_game_runtime_init(aether_game_runtime_t *g);
void aether_game_runtime_shutdown(aether_game_runtime_t *g);
aether_result_t aether_game_runtime_start(aether_game_runtime_t *g, aether_vec3_t spawn, f32 yaw);
void aether_game_runtime_update(aether_game_runtime_t *g, const aether_input_state_t *in, f32 dt);
void aether_game_runtime_pause(aether_game_runtime_t *g, bool paused);
void aether_game_runtime_damage_player(aether_game_runtime_t *g, const aether_damage_t *d);
aether_result_t aether_game_runtime_add_monster(aether_game_runtime_t *g, const aether_monster_t *m);
#ifdef __cplusplus
}
#endif
#endif
