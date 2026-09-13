#ifndef AETHER_PLAYER_WATER_H
#define AETHER_PLAYER_WATER_H
#include "../../core/AetherCore.h"
#include "../../core/AetherMath.h"
#ifdef __cplusplus
extern "C" {
#endif

typedef enum aether_water_level {
    AETHER_WATER_NONE = 0,
    AETHER_WATER_FEET = 1,
    AETHER_WATER_WAIST = 2,
    AETHER_WATER_EYES = 3
} aether_water_level_t;

typedef struct aether_player_water {
    bool enabled;
    aether_water_level_t level;
    f32 surface_z;
    f32 swim_speed;
    f32 buoyancy;
    f32 drag;
    f32 drown_time;
    f32 damage_timer;
    bool drowning;
} aether_player_water_t;

void aether_player_water_init(aether_player_water_t *w);
void aether_player_water_reset(aether_player_water_t *w);
void aether_player_water_set_surface(aether_player_water_t *w, f32 surface_z);
void aether_player_water_set_level(aether_player_water_t *w, aether_water_level_t level);
void aether_player_water_update(aether_player_water_t *w, aether_vec3_t *position,
                                aether_vec3_t *velocity, f32 eye_z, f32 dt);
bool aether_player_water_is_submerged(const aether_player_water_t *w);
bool aether_player_water_is_drowning(const aether_player_water_t *w);
#ifdef __cplusplus
}
#endif
#endif
