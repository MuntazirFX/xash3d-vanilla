#include "AetherShotgun.h"
void aethershotgun_init(aether_weapon_t *w) { aether_weapon_init(w,AETHER_WEAPON_SHOTGUN,"weapon_shotgun",8,20.00f,0.850f,2048.0f,false); }
bool aethershotgun_update(aether_weapon_t *w, f32 dt, bool trigger) { aether_weapon_tick(w,dt); return trigger ? aether_weapon_fire(w) : false; }
