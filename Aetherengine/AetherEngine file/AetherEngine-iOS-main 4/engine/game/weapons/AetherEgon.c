#include "AetherEgon.h"
void aetheregon_init(aether_weapon_t *w) { aether_weapon_init(w,AETHER_WEAPON_EGON,"weapon_egon",100,20.00f,0.100f,2048.0f,true); }
bool aetheregon_update(aether_weapon_t *w, f32 dt, bool trigger) { aether_weapon_tick(w,dt); return trigger ? aether_weapon_fire(w) : false; }
