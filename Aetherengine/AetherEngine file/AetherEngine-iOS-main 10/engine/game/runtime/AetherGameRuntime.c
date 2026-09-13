#include "AetherGameRuntime.h"
#include "../weapons/AetherCrowbar.h"
#include "../weapons/AetherGlock.h"
#include "../monsters/AetherHeadcrab.h"
#include <math.h>
#include <string.h>


static aether_weapon_t *weapon_slot(aether_game_runtime_t *g, aether_weapon_id_t id) {
    if (!g || id <= AETHER_WEAPON_NONE || id >= AETHER_RUNTIME_MAX_WEAPONS) return NULL;
    return &g->weapons[(u32)id];
}

static void init_weapon_set(aether_game_runtime_t *g) {
    memset(g->weapons, 0, sizeof g->weapons);

    aether_crowbar_init(&g->weapons[AETHER_WEAPON_CROWBAR]);
    aether_glock_init(&g->weapons[AETHER_WEAPON_GLOCK]);

    /* The reserve values are engine-side gameplay state. The actual
       sounds/models remain in the user's game data. */
    g->weapons[AETHER_WEAPON_GLOCK].ammo = 68;
    g->weapons[AETHER_WEAPON_GLOCK].ammo_max = 250;

    g->active_weapon = AETHER_WEAPON_CROWBAR;
}

void aether_game_runtime_init(aether_game_runtime_t *g) {
    if (!g) return;
    memset(g, 0, sizeof *g);
    aether_player_init(&g->player);
    aether_player_health_init(&g->health);
    aether_player_inventory_init(&g->inventory);
    aether_player_death_init(&g->death);
    init_weapon_set(g);

    aether_player_inventory_add_weapon(&g->inventory, AETHER_WEAPON_CROWBAR);
    aether_player_inventory_add_weapon(&g->inventory, AETHER_WEAPON_GLOCK);
    (void)aether_player_inventory_add_ammo(&g->inventory, "9mm", 68, 250);

    g->state = AETHER_GAME_LOADING;
}

void aether_game_runtime_shutdown(aether_game_runtime_t *g) {
    if (g) memset(g, 0, sizeof *g);
}

aether_result_t aether_game_runtime_start(aether_game_runtime_t *g,
                                           aether_vec3_t spawn,
                                           f32 yaw) {
    if (!g) return AETHER_ERR_INVALID_ARG;

    g->spawn_position = spawn;
    g->spawn_yaw = yaw;
    aether_player_set_position(&g->player, spawn);
    g->player.yaw = yaw;
    g->player.pitch = 0.0f;
    aether_player_health_set(&g->health, g->health.max_health, 0.0f);
    g->death.dead = false;
    g->death.timer = 0.0f;
    g->active_weapon = AETHER_WEAPON_CROWBAR;
    g->state = AETHER_GAME_RUNNING;
    return AETHER_OK;
}

void aether_game_runtime_set_collision(aether_game_runtime_t *g,
                                       aether_collision_t *collision) {
    if (g) g->collision = collision;
}

void aether_game_runtime_pause(aether_game_runtime_t *g, bool paused) {
    if (!g) return;
    if (paused && g->state == AETHER_GAME_RUNNING)
        g->state = AETHER_GAME_PAUSED;
    else if (!paused && g->state == AETHER_GAME_PAUSED)
        g->state = AETHER_GAME_RUNNING;
}

void aether_game_runtime_damage_player(aether_game_runtime_t *g,
                                       const aether_damage_t *d) {
    if (!g || !d || g->state != AETHER_GAME_RUNNING) return;
    if (aether_player_apply_damage(&g->health, d) <= 0.0f) return;
    if (!aether_player_health_alive(&g->health)) {
        aether_player_death_kill(&g->death);
        g->state = AETHER_GAME_DEAD;
    }
}

aether_result_t aether_game_runtime_add_monster(aether_game_runtime_t *g,
                                                 const aether_monster_t *m) {
    if (!g || !m) return AETHER_ERR_INVALID_ARG;
    if (g->monster_count >= AETHER_RUNTIME_MAX_MONSTERS)
        return AETHER_ERR_OUT_OF_MEM;
    g->monsters[g->monster_count++] = *m;
    return AETHER_OK;
}

static bool fire_hits_monster(aether_game_runtime_t *g,
                              const aether_weapon_t *w,
                              aether_monster_t **out_monster) {
    if (out_monster) *out_monster = NULL;
    if (!g || !w) return false;

    const aether_vec3_t eye = aether_player_eye_position(&g->player);
    const aether_vec3_t fwd = aether_player_forward(&g->player);
    const f32 range = w->range > 0.0f ? w->range : 64.0f;
    const f32 cos_limit = (w->id == AETHER_WEAPON_CROWBAR) ? 0.65f : 0.94f;

    f32 best = range + 1.0f;
    aether_monster_t *best_m = NULL;

    for (u32 i = 0; i < g->monster_count; ++i) {
        aether_monster_t *m = &g->monsters[i];
        if (!m->alive) continue;

        aether_vec3_t to = {
            m->position.x - eye.x,
            m->position.y - eye.y,
            m->position.z - eye.z
        };
        f32 dist = sqrtf(to.x*to.x + to.y*to.y + to.z*to.z);
        if (dist <= 0.001f || dist > range) continue;

        f32 inv = 1.0f / dist;
        f32 dot = fwd.x*to.x*inv + fwd.y*to.y*inv + fwd.z*to.z*inv;
        if (dot < cos_limit) continue;

        if (dist < best) {
            best = dist;
            best_m = m;
        }
    }

    if (out_monster) *out_monster = best_m;
    return best_m != NULL;
}

static void select_next_weapon(aether_game_runtime_t *g, i32 direction) {
    if (!g || g->inventory.weapon_count == 0) return;
    i32 current = aether_player_inventory_current(&g->inventory);
    if (current < 0) current = 0;

    i32 next = current;
    for (u32 tries = 0; tries < g->inventory.weapon_count; ++tries) {
        next += direction;
        if (next < 0) next = (i32)g->inventory.weapon_count - 1;
        if ((u32)next >= g->inventory.weapon_count) next = 0;
        u32 id = g->inventory.weapon_ids[next];
        if (weapon_slot(g, (aether_weapon_id_t)id)) {
            aether_player_inventory_set_current(&g->inventory, next);
            g->active_weapon = (aether_weapon_id_t)id;
            return;
        }
    }
}

static void update_death(aether_game_runtime_t *g, f32 dt) {
    if (!g || g->state != AETHER_GAME_DEAD) return;
    if (!aether_player_death_update(&g->death, dt)) return;

    aether_player_death_respawn(&g->death, &g->health);
    aether_player_set_position(&g->player, g->spawn_position);
    g->player.yaw = g->spawn_yaw;
    g->player.pitch = 0.0f;
    g->state = AETHER_GAME_RUNNING;
}

void aether_game_runtime_update(aether_game_runtime_t *g,
                                const aether_input_state_t *in,
                                f32 dt) {
    if (!g || !in) return;
    if (dt < 0.0f) dt = 0.0f;
    if (dt > 0.1f) dt = 0.1f;

    if (g->state == AETHER_GAME_DEAD) {
        update_death(g, dt);
        return;
    }
    if (g->state != AETHER_GAME_RUNNING) return;

    g->time += dt;
    g->ticks++;

    aether_player_update(&g->player, in, g->collision, dt);

    if (in->actions[AETHER_ACTION_WEAPON_NEXT])
        select_next_weapon(g, +1);
    if (in->actions[AETHER_ACTION_WEAPON_PREV])
        select_next_weapon(g, -1);

    aether_weapon_t *w = weapon_slot(g, g->active_weapon);
    if (w) {
        aether_weapon_tick(w, dt);
        w->attacking = false;

        if (in->actions[AETHER_ACTION_RELOAD] && w->id != AETHER_WEAPON_CROWBAR)
            (void)aether_weapon_reload(w);

        if (in->actions[AETHER_ACTION_FIRE]) {
            bool fired = false;
            if (w->id == AETHER_WEAPON_CROWBAR)
                fired = aether_crowbar_attack(w);
            else if (w->id == AETHER_WEAPON_GLOCK)
                fired = aether_glock_attack(w);
            else
                fired = aether_weapon_fire(w);

            if (fired) {
                g->shots_fired++;
                aether_monster_t *hit = NULL;
                if (fire_hits_monster(g, w, &hit)) {
                    g->shots_hit++;
                    if (aether_monster_damage(hit, w->damage) > 0.0f && !hit->alive)
                        g->monsters_killed++;
                }
            }
        }
    }

    const aether_vec3_t target = aether_player_eye_position(&g->player);
    for (u32 i = 0; i < g->monster_count; ++i) {
        aether_monster_t *m = &g->monsters[i];
        if (!m->alive) continue;

        aether_monster_update(m, target, dt);
        if (strcmp(m->classname, "monster_headcrab") == 0 &&
            aether_headcrab_can_attack(m)) {
            f32 dmg = aether_headcrab_attack(m);
            aether_damage_t d = {
                dmg, 0.5f, AETHER_DAMAGE_MELEE,
                m->position, (aether_vec3_t){0,0,0}, m
            };
            aether_game_runtime_damage_player(g, &d);
            if (g->state == AETHER_GAME_DEAD) break;
        }
    }
}

const aether_player_t *aether_game_runtime_player(const aether_game_runtime_t *g) {
    return g ? &g->player : NULL;
}
const aether_player_health_t *aether_game_runtime_health(const aether_game_runtime_t *g) {
    return g ? &g->health : NULL;
}
const aether_weapon_t *aether_game_runtime_weapon(const aether_game_runtime_t *g) {
    return g ? weapon_slot((aether_game_runtime_t *)g, g->active_weapon) : NULL;
}
aether_game_state_t aether_game_runtime_state(const aether_game_runtime_t *g) {
    return g ? g->state : AETHER_GAME_LOADING;
}
u32 aether_game_runtime_monster_count(const aether_game_runtime_t *g) {
    return g ? g->monster_count : 0;
}
const aether_monster_t *aether_game_runtime_monster_at(const aether_game_runtime_t *g, u32 index) {
    if (!g || index >= g->monster_count) return NULL;
    return &g->monsters[index];
}
