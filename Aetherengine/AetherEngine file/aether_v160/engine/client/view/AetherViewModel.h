#ifndef AETHER_VIEWMODEL_H
#define AETHER_VIEWMODEL_H

#include "../../core/AetherCore.h"
#include "../../core/AetherMath.h"
#include "../../game/weapons/AetherWeapon.h"
#include "../../input/AetherInput.h"

#ifdef __cplusplus
extern "C" {
#endif

#define AETHER_VIEWMODEL_PATH_MAX 96

typedef struct aether_viewmodel {
    aether_weapon_id_t weapon;
    char path[AETHER_VIEWMODEL_PATH_MAX];
    f32 time;
    f32 bob_time;
    f32 bob_amount;
    f32 sway_x;
    f32 sway_y;
    f32 offset_x;
    f32 offset_y;
    f32 offset_z;
    f32 scale;
    bool visible;
} aether_viewmodel_t;

void aether_viewmodel_init(aether_viewmodel_t *vm);
void aether_viewmodel_set_weapon(aether_viewmodel_t *vm, aether_weapon_id_t weapon);
void aether_viewmodel_update(aether_viewmodel_t *vm,
                             const aether_input_state_t *input,
                             f32 recoil_pitch,
                             f32 recoil_yaw,
                             f32 dt);
void aether_viewmodel_reset(aether_viewmodel_t *vm);

const char *aether_viewmodel_path(const aether_viewmodel_t *vm);
aether_weapon_id_t aether_viewmodel_weapon(const aether_viewmodel_t *vm);
void aether_viewmodel_offset(const aether_viewmodel_t *vm, f32 out_xyz[3]);
f32 aether_viewmodel_scale(const aether_viewmodel_t *vm);
bool aether_viewmodel_visible(const aether_viewmodel_t *vm);

#ifdef __cplusplus
}
#endif
#endif
