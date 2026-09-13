#include "AetherSnarks.h"
void aethersnarks_init(aether_weapon_t *w) { aether_weapon_init(w,AETHER_WEAPON_SNARK,"weapon_snark",1,10.00f,0.400f,512.0f,false); }
bool aethersnarks_update(aether_weapon_t *w, f32 dt, bool trigger) { aether_weapon_tick(w,dt); return trigger ? aether_weapon_fire(w) : false; }
