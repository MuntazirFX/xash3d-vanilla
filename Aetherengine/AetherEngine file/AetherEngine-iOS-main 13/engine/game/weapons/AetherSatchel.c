#include "AetherSatchel.h"
void aethersatchel_init(aether_weapon_t *w) { aether_weapon_init(w,AETHER_WEAPON_SATCHEL,"weapon_satchel",1,100.00f,1.000f,1024.0f,false); }
bool aethersatchel_update(aether_weapon_t *w, f32 dt, bool trigger) { aether_weapon_tick(w,dt); return trigger ? aether_weapon_fire(w) : false; }
