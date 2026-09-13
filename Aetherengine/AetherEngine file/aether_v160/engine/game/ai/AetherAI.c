#include "AetherAI.h"
#include <math.h>
#include <string.h>

static f32 clampf_(f32 v, f32 lo, f32 hi) { return v < lo ? lo : (v > hi ? hi : v); }
static f32 dist3_(aether_vec3_t a, aether_vec3_t b) {
    f32 x=a.x-b.x, y=a.y-b.y, z=a.z-b.z;
    return sqrtf(x*x+y*y+z*z);
}
static void set_state_(aether_ai_t *ai, aether_ai_state_t s) {
    if (ai->state != s) { ai->state = s; ai->state_changes++; }
}

void aether_ai_init(aether_ai_t *ai) {
    if (!ai) return;
    memset(ai, 0, sizeof *ai);
    ai->enabled = true;
    ai->state = AETHER_AI_IDLE;
    ai->sight_range = 768.0f;
    ai->attack_range = 64.0f;
    ai->lose_target_range = 1024.0f;
    ai->think_interval = 0.05f;
}
void aether_ai_reset(aether_ai_t *ai) {
    if (!ai) return;
    bool enabled = ai->enabled;
    aether_ai_init(ai);
    ai->enabled = enabled;
}
void aether_ai_set_ranges(aether_ai_t *ai, f32 sight, f32 attack, f32 lose) {
    if (!ai) return;
    if (sight > 0) ai->sight_range = sight;
    if (attack > 0) ai->attack_range = attack;
    if (lose > 0) ai->lose_target_range = lose;
}

void aether_ai_update(aether_ai_t *ai, aether_monster_t *m, u32 target_id,
                     aether_vec3_t target_position, f32 dt) {
    if (!ai || !m || !m->alive || !ai->enabled) return;
    dt = clampf_(dt, 0.0f, 0.1f);
    ai->think_timer = fmaxf(0.0f, ai->think_timer - dt);
    ai->attack_timer = fmaxf(0.0f, ai->attack_timer - dt);
    m->attack_cooldown = fmaxf(0.0f, m->attack_cooldown - dt);

    f32 distance = dist3_(m->position, target_position);
    const bool can_see = distance <= ai->sight_range;
    const bool has_target = (ai->target_id != 0);

    if (ai->think_timer <= 0.0f) {
        ai->think_timer = ai->think_interval;
        if (can_see) {
            ai->target_id = target_id;
            ai->last_seen_position = target_position;
            ai->has_last_seen = true;
        } else if (has_target && distance > ai->lose_target_range) {
            ai->target_id = 0;
            ai->has_last_seen = false;
        }

        if (!ai->target_id) {
            set_state_(ai, AETHER_AI_IDLE);
            m->state = AETHER_MONSTER_IDLE;
        } else if (distance <= ai->attack_range) {
            set_state_(ai, AETHER_AI_ATTACK);
            m->state = AETHER_MONSTER_COMBAT;
        } else {
            set_state_(ai, can_see ? AETHER_AI_CHASE : AETHER_AI_ALERT);
            m->state = AETHER_MONSTER_ALERT;
        }
    }

    /* Steering runs every frame; only the expensive decision/thinking step is
       throttled. This keeps movement at the configured monster speed. */
    if (ai->target_id && ai->state == AETHER_AI_CHASE) {
        aether_vec3_t d = ai->has_last_seen ?
            (aether_vec3_t){ai->last_seen_position.x-m->position.x,
                            ai->last_seen_position.y-m->position.y,
                            ai->last_seen_position.z-m->position.z} :
            (aether_vec3_t){target_position.x-m->position.x,
                            target_position.y-m->position.y,
                            target_position.z-m->position.z};
        f32 len = sqrtf(d.x*d.x+d.y*d.y+d.z*d.z);
        if (len > 0.001f) {
            f32 inv=1.0f/len;
            m->velocity.x=d.x*inv*m->speed;
            m->velocity.y=d.y*inv*m->speed;
            m->velocity.z=0.0f;
            m->position.x += m->velocity.x*dt;
            m->position.y += m->velocity.y*dt;
        }
    } else {
        m->velocity = (aether_vec3_t){0,0,0};
    }
}
bool aether_ai_can_attack(const aether_ai_t *ai) {
    return ai && ai->enabled && ai->target_id != 0 && ai->state == AETHER_AI_ATTACK && ai->attack_timer <= 0.0f;
}
bool aether_ai_take_attack(aether_ai_t *ai) {
    if (!aether_ai_can_attack(ai)) return false;
    ai->attack_timer = ai->attack_cooldown > 0.0f ? ai->attack_cooldown : 1.0f;
    ai->attacks++;
    return true;
}
aether_ai_state_t aether_ai_state(const aether_ai_t *ai) { return ai ? ai->state : AETHER_AI_DEAD; }

void aetherai_init(aetherai_state_t *s) { aether_ai_init(s); }
void aetherai_update(aetherai_state_t *s, f32 dt) {
    if (!s || !s->enabled) return;
    s->think_timer = fmaxf(0.0f, s->think_timer-dt);
}
void aetherai_reset(aetherai_state_t *s) { aether_ai_reset(s); }
void aetherai_event(aetherai_state_t *s) { if (s) s->state_changes++; }
