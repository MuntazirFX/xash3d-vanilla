#ifndef AETHER_HUD_H
#define AETHER_HUD_H
#include "../../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aether_hud { f32 health,armor; i32 ammo_clip,ammo_reserve; u32 weapon_id; f32 damage_flash; f32 message_timer; char message[128]; bool crosshair,visible; } aether_hud_t;
void aether_hud_init(aether_hud_t*h);
void aether_hud_set_player(aether_hud_t*h,f32 health,f32 armor,i32 clip,i32 reserve,u32 weapon);
void aether_hud_damage(aether_hud_t*h,f32 intensity);
void aether_hud_message(aether_hud_t*h,const char*text,f32 seconds);
void aether_hud_update(aether_hud_t*h,f32 dt);
#ifdef __cplusplus
}
#endif
#endif
