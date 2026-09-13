#include "AetherRPG.h"
void aetherrpg_init(aether_weapon_t *w) { aether_weapon_init(w,AETHER_WEAPON_RPG,"weapon_rpg",1,100.00f,1.000f,4096.0f,false); }
bool aetherrpg_update(aether_weapon_t *w, f32 dt, bool trigger) { aether_weapon_tick(w,dt); return trigger ? aether_weapon_fire(w) : false; }
