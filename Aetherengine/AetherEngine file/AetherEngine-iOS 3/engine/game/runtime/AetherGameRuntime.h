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
#include "../../client/hud/AetherHUD.h"
#include "../AetherPickup.h"
#include "../AetherCombat.h"
#include "../ai/AetherAI.h"
#include "../../client/presentation/AetherCombatPresentation.h"
#include "../../client/view/AetherViewModel.h"
#include "../../client/effects/AetherCombatFX.h"
#include "../npc/AetherNPCProfile.h"

#ifdef __cplusplus
extern "C" {
#endif

#define AETHER_RUNTIME_MAX_MONSTERS 128
#define AETHER_RUNTIME_MAX_WEAPONS  15
#define AETHER_RUNTIME_MAX_PICKUPS  256

typedef enum aether_game_state {
    AETHER_GAME_LOADING = 0,
    AETHER_GAME_RUNNING,
    AETHER_GAME_PAUSED,
    AETHER_GAME_DEAD
} aether_game_state_t;

typedef struct aether_game_runtime {
    aether_game_state_t state;
    f32 time;
    u64 ticks;

    aether_player_t player;
    aether_player_health_t health;
    aether_player_inventory_t inventory;
    aether_player_death_t death;

    aether_weapon_t weapons[AETHER_RUNTIME_MAX_WEAPONS];
    aether_weapon_id_t active_weapon;

    aether_monster_t monsters[AETHER_RUNTIME_MAX_MONSTERS];
    aether_ai_t monster_ai[AETHER_RUNTIME_MAX_MONSTERS];
    u32 monster_count;

    aether_pickup_t pickups[AETHER_RUNTIME_MAX_PICKUPS];
    u32 pickup_count;

    aether_collision_t *collision; /* borrowed; owned by platform/world layer */
    aether_vec3_t spawn_position;
    f32 spawn_yaw;

    u32 shots_fired;
    u32 monsters_killed;
    u32 shots_hit;
    bool fire_was_down;
    aether_hud_t hud;
    aether_combat_event_t last_event;
    u64 combat_events;
    aether_combat_presentation_t presentation;
    aether_viewmodel_t viewmodel;
    aether_combat_fx_t combat_fx;
} aether_game_runtime_t;

void aether_game_runtime_init(aether_game_runtime_t *g);
void aether_game_runtime_shutdown(aether_game_runtime_t *g);
aether_result_t aether_game_runtime_start(aether_game_runtime_t *g, aether_vec3_t spawn, f32 yaw);
void aether_game_runtime_set_collision(aether_game_runtime_t *g, aether_collision_t *collision);
void aether_game_runtime_update(aether_game_runtime_t *g, const aether_input_state_t *in, f32 dt);
void aether_game_runtime_pause(aether_game_runtime_t *g, bool paused);
void aether_game_runtime_damage_player(aether_game_runtime_t *g, const aether_damage_t *d);
aether_result_t aether_game_runtime_add_monster(aether_game_runtime_t *g, const aether_monster_t *m);
aether_result_t aether_game_runtime_spawn_monster(aether_game_runtime_t *g,
                                                   u32 id, const char *classname,
                                                   aether_vec3_t position);
aether_result_t aether_game_runtime_add_pickup(aether_game_runtime_t *g, const aether_pickup_t *p);
u32 aether_game_runtime_pickup_count(const aether_game_runtime_t *g);
const aether_combat_event_t *aether_game_runtime_last_event(const aether_game_runtime_t *g);
const aether_combat_presentation_t *aether_game_runtime_presentation(const aether_game_runtime_t *g);
const aether_viewmodel_t *aether_game_runtime_viewmodel(const aether_game_runtime_t *g);
const aether_combat_fx_t *aether_game_runtime_combat_fx(const aether_game_runtime_t *g);
void aether_game_runtime_clear_event(aether_game_runtime_t *g);

const aether_player_t *aether_game_runtime_player(const aether_game_runtime_t *g);
const aether_player_health_t *aether_game_runtime_health(const aether_game_runtime_t *g);
const aether_weapon_t *aether_game_runtime_weapon(const aether_game_runtime_t *g);
aether_game_state_t aether_game_runtime_state(const aether_game_runtime_t *g);
u32 aether_game_runtime_monster_count(const aether_game_runtime_t *g);
const aether_monster_t *aether_game_runtime_monster_at(const aether_game_runtime_t *g, u32 index);

#ifdef __cplusplus
}
#endif
#endif
