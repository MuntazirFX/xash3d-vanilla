#include "AetherPlayerWater.h"
#include <string.h>

void aether_player_water_init(aether_player_water_t *w) {
    if (!w) return;
    memset(w, 0, sizeof *w);
    w->enabled = true;
    w->level = AETHER_WATER_NONE;
    w->surface_z = 0.0f;
    w->swim_speed = 180.0f;
    w->buoyancy = 0.65f;
    w->drag = 3.0f;
    w->drown_time = 12.0f;
}
void aether_player_water_reset(aether_player_water_t *w) {
    if (!w) return;
    const bool enabled = w->enabled;
    aether_player_water_init(w);
    w->enabled = enabled;
}
void aether_player_water_set_surface(aether_player_water_t *w, f32 surface_z) {
    if (w) w->surface_z = surface_z;
}
void aether_player_water_set_level(aether_player_water_t *w, aether_water_level_t level) {
    if (!w) return;
    if (level < AETHER_WATER_NONE || level > AETHER_WATER_EYES) level = AETHER_WATER_NONE;
    w->level = level;
    if (level != AETHER_WATER_EYES) {
        w->drowning = false;
        w->drown_time = 12.0f;
        w->damage_timer = 0.0f;
    }
}
void aether_player_water_update(aether_player_water_t *w, aether_vec3_t *position,
                                aether_vec3_t *velocity, f32 eye_z, f32 dt) {
    if (!w || !position || !velocity || !w->enabled) return;
    if (dt < 0.0f) dt = 0.0f;
    if (w->level == AETHER_WATER_NONE) return;

    /* Underwater movement is deliberately deterministic; input code can scale
       velocity before this function. We only apply water physics here. */
    const f32 factor = 1.0f / (1.0f + w->drag * dt);
    velocity->x *= factor;
    velocity->y *= factor;
    velocity->z *= factor;

    if (w->level >= AETHER_WATER_WAIST && velocity->z < 0.0f)
        velocity->z += (-velocity->z) * w->buoyancy * dt;

    if (w->level == AETHER_WATER_EYES) {
        w->drown_time -= dt;
        w->drowning = w->drown_time <= 0.0f;
        if (w->drowning) {
            w->damage_timer += dt;
            if (w->damage_timer >= 2.0f) w->damage_timer = 0.0f;
        }
        /* Keep a fully submerged player's eye position below the surface. */
        if (eye_z > w->surface_z && position->z > w->surface_z)
            position->z = w->surface_z - 1.0f;
    }
}
bool aether_player_water_is_submerged(const aether_player_water_t *w) {
    return w && w->enabled && w->level == AETHER_WATER_EYES;
}
bool aether_player_water_is_drowning(const aether_player_water_t *w) {
    return w && w->enabled && w->drowning;
}
