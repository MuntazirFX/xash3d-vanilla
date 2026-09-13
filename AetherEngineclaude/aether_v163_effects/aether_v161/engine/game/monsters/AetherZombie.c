#include "AetherZombie.h"

void aetherzombie_init(aether_monster_t *m, u32 id, aether_vec3_t p) {
    /* Slow, tanky melee brawler: more HP than a headcrab, half the move speed,
     * short attack range, long wind-up, heavy hit. */
    aether_monster_init(m, id, "monster_zombie", p, 50.0f, 40.0f);
    m->attack_range = 42.0f;
    m->perception_range = 640.0f;
    m->attack_windup = 0.8f;   /* slow claw swing, telegraphed */
    m->attack_damage = 20.0f;
}

void aetherzombie_update(aether_monster_t *m, aether_vec3_t target, f32 dt) {
    aether_monster_update(m, target, dt);
}

bool aetherzombie_can_attack(const aether_monster_t *m) {
    return m && m->alive && m->state == AETHER_MONSTER_COMBAT && m->attack_cooldown <= 0;
}

f32 aetherzombie_attack(aether_monster_t *m) {
    if (!aetherzombie_can_attack(m)) return 0;
    m->attack_cooldown = 2.0f; /* long recovery after each swing */
    return m->attack_damage;
}
