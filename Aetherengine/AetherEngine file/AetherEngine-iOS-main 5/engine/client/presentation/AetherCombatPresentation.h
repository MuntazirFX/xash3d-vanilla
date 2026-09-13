#ifndef AETHER_COMBAT_PRESENTATION_H
#define AETHER_COMBAT_PRESENTATION_H

#include "../../core/AetherCore.h"
#include "../../core/AetherMath.h"
#include "../effects/AetherMuzzleFlash.h"
#include "../effects/AetherImpact.h"
#include "../sound/AetherWeaponSnd.h"
#include "../../anim/AetherWeaponAnim.h"
#include "../../game/AetherCombat.h"

#ifdef __cplusplus
extern "C" {
#endif

#define AETHER_VM_PATH_MAX 96

typedef struct aether_combat_presentation {
    aethermuzzleflash_state_t muzzle_flash;
    aetherimpact_state_t impact;
    aetherweaponsnd_state_t weapon_sound;
    aetherweaponanim_state_t weapon_anim;

    u64 event_sequence;
    u32 muzzle_flash_frames;
    f32 muzzle_flash_time;
    f32 recoil_pitch;
    f32 recoil_yaw;
    f32 impact_time;
    aether_vec3_t impact_position;
    char viewmodel[AETHER_VM_PATH_MAX];
    char event_text[128];
} aether_combat_presentation_t;

void aether_combat_presentation_init(aether_combat_presentation_t *p);
void aether_combat_presentation_update(aether_combat_presentation_t *p, f32 dt);
void aether_combat_presentation_consume(aether_combat_presentation_t *p,
                                        const aether_combat_event_t *event);
void aether_combat_presentation_reset(aether_combat_presentation_t *p);

const char *aether_combat_presentation_viewmodel(const aether_combat_presentation_t *p);
f32 aether_combat_presentation_muzzle_flash(const aether_combat_presentation_t *p);
f32 aether_combat_presentation_recoil_pitch(const aether_combat_presentation_t *p);
f32 aether_combat_presentation_recoil_yaw(const aether_combat_presentation_t *p);
const char *aether_combat_presentation_event_text(const aether_combat_presentation_t *p);

#ifdef __cplusplus
}
#endif
#endif
