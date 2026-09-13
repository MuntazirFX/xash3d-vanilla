#include "AetherNPCCombat.h"

f32 aether_npc_attack_damage(const aether_monster_t *monster) {
    if (!monster) return 0.0f;
    const aether_npc_profile_t *p = aether_npc_profile_for_classname(monster->classname);
    return p ? p->attack_damage : monster->attack_damage;
}

void aether_npc_mark_attack(aether_monster_t *monster) {
    if (!monster) return;
    const aether_npc_profile_t *p = aether_npc_profile_for_classname(monster->classname);
    monster->attack_cooldown = p ? p->attack_cooldown : 1.0f;
}

bool aether_npc_is_hostile(const aether_monster_t *monster) {
    if (!monster) return false;
    const aether_npc_profile_t *p = aether_npc_profile_for_classname(monster->classname);
    return p ? !p->friendly : true;
}
