#include "AetherCombat.h"
#include <string.h>

void aether_combat_event_clear(aether_combat_event_t *event) {
    if (event) memset(event, 0, sizeof *event);
}

void aether_combat_event_make(aether_combat_event_t *event,
                              aether_combat_event_type_t type,
                              aether_weapon_id_t weapon,
                              u32 target_id,
                              f32 damage,
                              aether_vec3_t origin,
                              aether_vec3_t direction,
                              u64 sequence) {
    if (!event) return;
    event->type = type;
    event->weapon = weapon;
    event->target_id = target_id;
    event->damage = damage;
    event->origin = origin;
    event->direction = direction;
    event->sequence = sequence;
}
