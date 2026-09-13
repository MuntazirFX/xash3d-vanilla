#ifndef AETHER_WEAPON_H
#define AETHER_WEAPON_H
#include "../../core/AetherCore.h"
#include "../../core/AetherMath.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef enum { AETHER_WEAPON_NONE=0,AETHER_WEAPON_CROWBAR=1,AETHER_WEAPON_GLOCK=2,AETHER_WEAPON_PYTHON=3,AETHER_WEAPON_MP5=4,AETHER_WEAPON_SHOTGUN=5,AETHER_WEAPON_CROSSBOW=6,AETHER_WEAPON_RPG=7,AETHER_WEAPON_GAUSS=8,AETHER_WEAPON_EGON=9,AETHER_WEAPON_HIVEHAND=10,AETHER_WEAPON_GRENADE=11,AETHER_WEAPON_SATCHEL=12,AETHER_WEAPON_TRIPMINE=13,AETHER_WEAPON_SNARK=14 } aether_weapon_id_t;
typedef struct aether_weapon { aether_weapon_id_t id; char classname[32]; i32 clip, clip_max; i32 ammo, ammo_max; f32 fire_delay, cooldown; f32 damage; f32 range; bool automatic; bool attacking; } aether_weapon_t;
void aether_weapon_init(aether_weapon_t*w,aether_weapon_id_t id,const char*classname,i32 clip_max,f32 damage,f32 delay,f32 range,bool automatic);
void aether_weapon_tick(aether_weapon_t*w,f32 dt);
bool aether_weapon_can_fire(const aether_weapon_t*w);
bool aether_weapon_fire(aether_weapon_t*w);
bool aether_weapon_reload(aether_weapon_t*w);
#ifdef __cplusplus
}
#endif
#endif
