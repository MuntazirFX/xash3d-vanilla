#include "AetherNPCController.h"
#include <string.h>

void aether_npc_controller_init(aether_npc_controller_t *c) {
    if (!c) return;
    memset(c,0,sizeof *c);
    c->enabled=true;
    aether_ai_init(&c->ai);
    aether_npc_navigation_init(&c->navigation);
}
void aether_npc_controller_reset(aether_npc_controller_t *c) {
    if (!c) return;
    const bool enabled=c->enabled;
    aether_npc_controller_init(c);
    c->enabled=enabled;
}
void aether_npc_controller_set_target(aether_npc_controller_t *c,u32 target_id) {
    if (c) { c->target_id=target_id; c->ai.target_id=target_id; }
}
void aether_npc_controller_update(aether_npc_controller_t *c,
                                  const aether_pathfind_state_t *graph,
                                  aether_monster_t *monster,
                                  aether_vec3_t target_position,
                                  f32 dt) {
    if (!c || !monster || !c->enabled || !monster->alive) return;
    c->think_updates++;
    aether_ai_update(&c->ai,monster,c->target_id,target_position,dt);
    if (c->ai.state == AETHER_AI_CHASE && graph) {
        if (!aether_npc_navigation_update(&c->navigation,graph,monster,target_position,dt)) {
            /* Navigation is an enhancement, not a hard dependency: if no graph
               route exists, retain the AI's direct steering behavior. */
        }
    } else if (c->ai.state == AETHER_AI_ATTACK) {
        monster->velocity=(aether_vec3_t){0,0,0};
        c->attack_decisions++;
    }
}
bool aether_npc_controller_can_attack(const aether_npc_controller_t *c) {
    return c && c->enabled && aether_ai_can_attack(&c->ai);
}
