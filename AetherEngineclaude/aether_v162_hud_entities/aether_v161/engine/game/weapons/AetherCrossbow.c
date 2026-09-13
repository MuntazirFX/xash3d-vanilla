#include "AetherCrossbow.h"
void aethercrossbow_init(aether_weapon_t *w) { aether_weapon_init(w,AETHER_WEAPON_CROSSBOW,"weapon_crossbow",5,40.00f,1.500f,8192.0f,false); }
bool aethercrossbow_update(aether_weapon_t *w, f32 dt, bool trigger) { aether_weapon_tick(w,dt); return trigger ? aether_weapon_fire(w) : false; }
