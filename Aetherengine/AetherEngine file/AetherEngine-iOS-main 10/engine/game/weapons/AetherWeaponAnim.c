#include "AetherWeaponAnim.h"
void aetherweaponanim_init(aether_weapon_t *w) { aether_weapon_init(w,AETHER_WEAPON_NONE,"weapon_anim",1,0.00f,0.000f,0.0f,false); }
bool aetherweaponanim_update(aether_weapon_t *w, f32 dt, bool trigger) { aether_weapon_tick(w,dt); return trigger ? aether_weapon_fire(w) : false; }
