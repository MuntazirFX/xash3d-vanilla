#include "AetherCombatPresentation.h"
#include <stdio.h>
#include <string.h>

static const char *vm_for_weapon(aether_weapon_id_t id) {
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

void aether_combat_presentation_init(aether_combat_presentation_t *p) {
    if (!p) return;
    memset(p, 0, sizeof *p);
    aethermuzzleflash_init(&p->muzzle_flash);
    aetherimpact_init(&p->impact);
    aetherweaponsnd_init(&p->weapon_sound);
    aetherweaponanim_init(&p->weapon_anim);
    p->muzzle_flash.enabled = true;
    p->impact.enabled = true;
    p->weapon_sound.enabled = true;
    p->weapon_anim.enabled = true;
}

void aether_combat_presentation_reset(aether_combat_presentation_t *p) {
    aether_combat_presentation_init(p);
}

void aether_combat_presentation_update(aether_combat_presentation_t *p, f32 dt) {
    if (!p) return;
    if (dt < 0) dt = 0;
    aethermuzzleflash_update(&p->muzzle_flash, dt);
    aetherimpact_update(&p->impact, dt);
    aetherweaponsnd_update(&p->weapon_sound, dt);
    aetherweaponanim_update(&p->weapon_anim, dt);

    p->muzzle_flash_time -= dt;
    if (p->muzzle_flash_time < 0) p->muzzle_flash_time = 0;
    p->impact_time -= dt;
    if (p->impact_time < 0) p->impact_time = 0;

    /* Recoil decays smoothly instead of disappearing on the next frame. */
    const f32 decay = dt * 14.0f;
    if (p->recoil_pitch > 0) { p->recoil_pitch -= decay; if (p->recoil_pitch < 0) p->recoil_pitch = 0; }
    if (p->recoil_pitch < 0) { p->recoil_pitch += decay; if (p->recoil_pitch > 0) p->recoil_pitch = 0; }
    if (p->recoil_yaw > 0) { p->recoil_yaw -= decay; if (p->recoil_yaw < 0) p->recoil_yaw = 0; }
    if (p->recoil_yaw < 0) { p->recoil_yaw += decay; if (p->recoil_yaw > 0) p->recoil_yaw = 0; }
}

void aether_combat_presentation_consume(aether_combat_presentation_t *p,
                                        const aether_combat_event_t *event) {
    if (!p || !event || event->sequence == 0 || event->sequence == p->event_sequence) return;
    p->event_sequence = event->sequence;

    if (event->weapon > AETHER_WEAPON_NONE) {
        const char *vm = vm_for_weapon(event->weapon);
        snprintf(p->viewmodel, sizeof p->viewmodel, "%s", vm);
    }

    switch (event->type) {
        case AETHER_COMBAT_FIRED:
            p->muzzle_flash_time = 0.075f;
            p->muzzle_flash_frames++;
            p->recoil_pitch += 0.75f;
            p->recoil_yaw += ((event->sequence & 1u) ? 0.12f : -0.12f);
            aethermuzzleflash_event(&p->muzzle_flash);
            aetherweaponsnd_event(&p->weapon_sound);
            aetherweaponanim_event(&p->weapon_anim);
            snprintf(p->event_text, sizeof p->event_text, "%s fired", aether_weapon_name(event->weapon));
            break;
        case AETHER_COMBAT_HIT:
            p->impact_time = 0.12f;
            p->impact_position = event->origin;
            aetherimpact_event(&p->impact);
            snprintf(p->event_text, sizeof p->event_text, "Hit %.0f", event->damage);
            break;
        case AETHER_COMBAT_KILLED:
            p->impact_time = 0.18f;
            p->impact_position = event->origin;
            aetherimpact_event(&p->impact);
            snprintf(p->event_text, sizeof p->event_text, "Target down");
            break;
        case AETHER_COMBAT_EMPTY:
            snprintf(p->event_text, sizeof p->event_text, "No ammo");
            break;
        case AETHER_COMBAT_RELOADED:
            aetherweaponanim_event(&p->weapon_anim);
            aetherweaponsnd_event(&p->weapon_sound);
            snprintf(p->event_text, sizeof p->event_text, "Reload");
            break;
        case AETHER_COMBAT_SWITCHED:
            aetherweaponanim_event(&p->weapon_anim);
            snprintf(p->event_text, sizeof p->event_text, "%s", aether_weapon_name(event->weapon));
            break;
        case AETHER_COMBAT_PLAYER_HIT:
            snprintf(p->event_text, sizeof p->event_text, "Damage %.0f", event->damage);
            break;
        case AETHER_COMBAT_PLAYER_DIED:
            snprintf(p->event_text, sizeof p->event_text, "You died");
            break;
        default:
            break;
    }
}

const char *aether_combat_presentation_viewmodel(const aether_combat_presentation_t *p) {
    return p ? p->viewmodel : "";
}
f32 aether_combat_presentation_muzzle_flash(const aether_combat_presentation_t *p) {
    return p ? p->muzzle_flash_time : 0;
}
f32 aether_combat_presentation_recoil_pitch(const aether_combat_presentation_t *p) {
    return p ? p->recoil_pitch : 0;
}
f32 aether_combat_presentation_recoil_yaw(const aether_combat_presentation_t *p) {
    return p ? p->recoil_yaw : 0;
}
const char *aether_combat_presentation_event_text(const aether_combat_presentation_t *p) {
    return p ? p->event_text : "";
}
