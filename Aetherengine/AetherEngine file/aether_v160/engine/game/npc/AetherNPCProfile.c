#include "AetherNPCProfile.h"
#include <string.h>

static const aether_npc_profile_t k_profiles[] = {
    {"monster_headcrab",      20.0f,  72.0f,  768.0f,  52.0f,  10.0f, 1.20f, 0.20f, AETHER_NPC_ATTACK_MELEE,  false},
    {"monster_zombie",        50.0f,  40.0f,  768.0f,  54.0f,  20.0f, 1.30f, 0.35f, AETHER_NPC_ATTACK_MELEE,  false},
    {"monster_zombie_soldier",50.0f,  44.0f,  768.0f,  54.0f,  25.0f, 1.30f, 0.35f, AETHER_NPC_ATTACK_MELEE,  false},
    {"monster_zombie_gonome", 100.0f, 55.0f,  768.0f,  64.0f,  25.0f, 1.20f, 0.30f, AETHER_NPC_ATTACK_MELEE,  false},
    {"monster_houndeye",       60.0f,  70.0f,  900.0f,  96.0f,  20.0f, 2.00f, 0.55f, AETHER_NPC_ATTACK_RANGED, false},
    {"monster_bullsquid",      80.0f,  70.0f,  900.0f, 180.0f,  20.0f, 1.60f, 0.45f, AETHER_NPC_ATTACK_RANGED, false},
    {"monster_alien_grunt",    50.0f,  70.0f, 1024.0f, 256.0f,  15.0f, 1.00f, 0.25f, AETHER_NPC_ATTACK_RANGED, false},
    {"monster_alien_slave",    60.0f,  80.0f, 1024.0f, 300.0f,  25.0f, 2.00f, 0.55f, AETHER_NPC_ATTACK_RANGED, false},
    {"monster_controller",     60.0f,  55.0f, 1024.0f, 320.0f,  20.0f, 1.80f, 0.55f, AETHER_NPC_ATTACK_RANGED, false},
    {"monster_gargantua",     800.0f,  35.0f, 1200.0f, 120.0f,  40.0f, 1.50f, 0.45f, AETHER_NPC_ATTACK_MELEE,  false},
    {"monster_human_grunt",    50.0f,  60.0f, 1024.0f, 512.0f,   8.0f, 0.45f, 0.12f, AETHER_NPC_ATTACK_RANGED, false},
    {"monster_human_sergeant", 50.0f,  60.0f, 1024.0f, 512.0f,  10.0f, 0.45f, 0.12f, AETHER_NPC_ATTACK_RANGED, false},
    {"monster_turret",        100.0f,   0.0f, 1200.0f, 700.0f,   5.0f, 0.15f, 0.05f, AETHER_NPC_ATTACK_RANGED, false},
    {"monster_scientist",      20.0f,  45.0f,  512.0f,  48.0f,   0.0f, 1.00f, 0.00f, AETHER_NPC_ATTACK_NONE,    true},
    {"monster_barney",         35.0f,  60.0f,  768.0f, 512.0f,   8.0f, 0.45f, 0.12f, AETHER_NPC_ATTACK_RANGED, true},
    {"monster_gman",           50.0f,  55.0f,  512.0f,  48.0f,   0.0f, 1.00f, 0.00f, AETHER_NPC_ATTACK_NONE,    true},
    {"monster_ichthyosaur",   200.0f, 120.0f, 1024.0f,  96.0f,  20.0f, 1.20f, 0.25f, AETHER_NPC_ATTACK_MELEE,  false},
    {"monster_leech",           2.0f,  30.0f,  300.0f,  32.0f,   3.0f, 0.60f, 0.10f, AETHER_NPC_ATTACK_MELEE,  false},
    {"monster_barnacle",       35.0f,   0.0f,  512.0f,  48.0f,  10.0f, 1.00f, 0.20f, AETHER_NPC_ATTACK_MELEE,  false},
    {"monster_apache",         200.0f, 160.0f, 1600.0f, 900.0f,  12.0f, 0.30f, 0.08f, AETHER_NPC_ATTACK_RANGED, false},
    {"monster_osprey",         400.0f, 100.0f, 1600.0f, 900.0f,  10.0f, 0.40f, 0.08f, AETHER_NPC_ATTACK_RANGED, false}
};

const aether_npc_profile_t *aether_npc_profile_for_classname(const char *classname) {
    if (!classname) return NULL;
    for (u32 i = 0; i < (u32)(sizeof(k_profiles)/sizeof(k_profiles[0])); ++i)
        if (strcmp(k_profiles[i].classname, classname) == 0) return &k_profiles[i];
    return NULL;
}

void aether_npc_spawn(aether_monster_t *monster, u32 id, const char *classname, aether_vec3_t position) {
    if (!monster) return;
    const aether_npc_profile_t *p = aether_npc_profile_for_classname(classname);
    if (!p) {
        aether_monster_init(monster, id, classname ? classname : "monster_unknown", position, 25.0f, 40.0f);
        return;
    }
    aether_monster_init(monster, id, p->classname, position, p->max_health, p->speed);
    monster->perception_range = p->perception_range;
    monster->attack_range = p->attack_range;
    monster->attack_cooldown = p->attack_cooldown;
}

bool aether_npc_can_attack(const aether_monster_t *monster, f32 time_since_attack) {
    if (!monster || !monster->alive) return false;
    const aether_npc_profile_t *p = aether_npc_profile_for_classname(monster->classname);
    return p && p->attack_type != AETHER_NPC_ATTACK_NONE &&
           monster->attack_cooldown <= 0.0f && time_since_attack >= p->attack_windup;
}
