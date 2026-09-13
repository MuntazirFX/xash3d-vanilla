#include "AetherViewModel.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

static const char *path_for_weapon(aether_weapon_id_t id) {
    switch (id) {
        case AETHER_WEAPON_CROWBAR: return "models/v_crowbar.mdl";
        case AETHER_WEAPON_GLOCK: return "models/v_9mmhandgun.mdl";
        case AETHER_WEAPON_PYTHON: return "models/v_357.mdl";
        case AETHER_WEAPON_MP5: return "models/v_9mmAR.mdl";
        case AETHER_WEAPON_SHOTGUN: return "models/v_shotgun.mdl";
        case AETHER_WEAPON_CROSSBOW: return "models/v_crossbow.mdl";
        case AETHER_WEAPON_RPG: return "models/v_rpg.mdl";
        case AETHER_WEAPON_GAUSS: return "models/v_gauss.mdl";
        case AETHER_WEAPON_EGON: return "models/v_egon.mdl";
        case AETHER_WEAPON_HIVEHAND: return "models/v_hgun.mdl";
        case AETHER_WEAPON_GRENADE: return "models/v_grenade.mdl";
        case AETHER_WEAPON_SATCHEL: return "models/v_satchel.mdl";
        case AETHER_WEAPON_TRIPMINE: return "models/v_tripmine.mdl";
        case AETHER_WEAPON_SNARK: return "models/v_squeak.mdl";
        default: return "";
    }
}

void aether_viewmodel_init(aether_viewmodel_t *vm) {
    if (!vm) return;
    memset(vm, 0, sizeof *vm);
    vm->weapon = AETHER_WEAPON_NONE;
    vm->scale = 1.0f;
    vm->visible = false;
}

void aether_viewmodel_set_weapon(aether_viewmodel_t *vm, aether_weapon_id_t weapon) {
    if (!vm) return;
    vm->weapon = weapon;
    snprintf(vm->path, sizeof vm->path, "%s", path_for_weapon(weapon));
    vm->time = 0.0f;
    vm->bob_time = 0.0f;
    vm->sway_x = vm->sway_y = 0.0f;
    vm->visible = vm->path[0] != '\0';
}

void aether_viewmodel_update(aether_viewmodel_t *vm,
                             const aether_input_state_t *input,
                             f32 recoil_pitch,
                             f32 recoil_yaw,
                             f32 dt) {
    if (!vm) return;
    if (dt < 0.0f) dt = 0.0f;
    if (dt > 0.1f) dt = 0.1f;
    vm->time += dt;

    f32 move_x = input ? input->move_x : 0.0f;
    f32 move_y = input ? input->move_y : 0.0f;
    f32 speed = sqrtf(move_x * move_x + move_y * move_y);
    if (speed > 1.0f) speed = 1.0f;
    vm->bob_time += dt * (5.5f + 3.0f * speed);

    /* Small GoldSrc-style weapon sway/bob; values are model-space units. */
    const f32 target_bob = speed * 1.35f;
    vm->bob_amount += (target_bob - vm->bob_amount) * fminf(1.0f, dt * 10.0f);
    vm->offset_x = 1.5f * sinf(vm->bob_time * 0.5f) * vm->bob_amount;
    vm->offset_y = 1.0f * cosf(vm->bob_time) * vm->bob_amount;
    vm->offset_z = -0.8f * fabsf(sinf(vm->bob_time)) * vm->bob_amount;

    vm->sway_x += ((input ? input->look_dx : 0.0f) * 0.018f - vm->sway_x) * fminf(1.0f, dt * 12.0f);
    vm->sway_y += ((input ? input->look_dy : 0.0f) * 0.018f - vm->sway_y) * fminf(1.0f, dt * 12.0f);

    /* Recoil is already decaying in the combat presentation state. */
    vm->offset_x += recoil_yaw * 0.35f;
    vm->offset_z -= recoil_pitch * 0.55f;
}

void aether_viewmodel_reset(aether_viewmodel_t *vm) {
    if (!vm) return;
    aether_weapon_id_t weapon = vm->weapon;
    aether_viewmodel_init(vm);
    aether_viewmodel_set_weapon(vm, weapon);
}

const char *aether_viewmodel_path(const aether_viewmodel_t *vm) { return vm ? vm->path : ""; }
aether_weapon_id_t aether_viewmodel_weapon(const aether_viewmodel_t *vm) { return vm ? vm->weapon : AETHER_WEAPON_NONE; }
void aether_viewmodel_offset(const aether_viewmodel_t *vm, f32 out_xyz[3]) {
    if (!out_xyz) return;
    if (!vm) { out_xyz[0]=out_xyz[1]=out_xyz[2]=0.0f; return; }
    out_xyz[0] = vm->offset_x + vm->sway_x;
    out_xyz[1] = vm->offset_y + vm->sway_y;
    out_xyz[2] = vm->offset_z;
}
f32 aether_viewmodel_scale(const aether_viewmodel_t *vm) { return vm ? vm->scale : 1.0f; }
bool aether_viewmodel_visible(const aether_viewmodel_t *vm) { return vm ? vm->visible : false; }
