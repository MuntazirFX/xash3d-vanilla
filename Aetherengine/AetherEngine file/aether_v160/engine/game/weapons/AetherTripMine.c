#include "AetherTripMine.h"
void aethertripmine_init(aether_weapon_t *w) { aether_weapon_init(w,AETHER_WEAPON_TRIPMINE,"weapon_tripmine",1,120.00f,1.000f,1024.0f,false); }
bool aethertripmine_update(aether_weapon_t *w, f32 dt, bool trigger) { aether_weapon_tick(w,dt); return trigger ? aether_weapon_fire(w) : false; }
