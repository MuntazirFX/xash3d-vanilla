#include "AetherGauss.h"
void aethergauss_init(aether_weapon_t *w) { aether_weapon_init(w,AETHER_WEAPON_GAUSS,"weapon_gauss",20,25.00f,0.150f,8192.0f,false); }
bool aethergauss_update(aether_weapon_t *w, f32 dt, bool trigger) { aether_weapon_tick(w,dt); return trigger ? aether_weapon_fire(w) : false; }
