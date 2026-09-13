#include "AetherHivehand.h"
void aetherhivehand_init(aether_weapon_t *w) { aether_weapon_init(w,AETHER_WEAPON_HIVEHAND,"weapon_hornetgun",8,15.00f,0.200f,4096.0f,false); }
bool aetherhivehand_update(aether_weapon_t *w, f32 dt, bool trigger) { aether_weapon_tick(w,dt); return trigger ? aether_weapon_fire(w) : false; }
