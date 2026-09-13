#ifndef AETHER_NPC_CONTROLLER_H
#define AETHER_NPC_CONTROLLER_H

#include "AetherAI.h"
#include "AetherNPCNavigation.h"
#include "../npc/AetherNPCProfile.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct aether_npc_controller {
    bool enabled;
    aether_ai_t ai;
    aether_npc_navigation_t navigation;
    u32 target_id;
    u32 think_updates;
    u32 attack_decisions;
} aether_npc_controller_t;

void aether_npc_controller_init(aether_npc_controller_t *controller);
void aether_npc_controller_reset(aether_npc_controller_t *controller);
void aether_npc_controller_set_target(aether_npc_controller_t *controller, u32 target_id);
void aether_npc_controller_update(aether_npc_controller_t *controller,
                                   const aether_pathfind_state_t *graph,
                                   aether_monster_t *monster,
                                   aether_vec3_t target_position,
                                   f32 dt);
bool aether_npc_controller_can_attack(const aether_npc_controller_t *controller);

#ifdef __cplusplus
}
#endif
#endif
