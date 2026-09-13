#ifndef AETHER_AETHERAMMO_H
#define AETHER_AETHERAMMO_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aether_hud_ammo_state { bool enabled; f32 value; u32 events; char text[128]; } aether_hud_ammo_state_t;
void aether_hud_ammo_init(aether_hud_ammo_state_t *s);
void aether_hud_ammo_update(aether_hud_ammo_state_t *s, f32 dt);
void aether_hud_ammo_reset(aether_hud_ammo_state_t *s);
void aether_hud_ammo_event(aether_hud_ammo_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
