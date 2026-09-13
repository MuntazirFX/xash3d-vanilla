#include "AetherMP5.h"
void aethermp5_init(aether_weapon_t *w) { aether_weapon_init(w,AETHER_WEAPON_MP5,"weapon_9mmAR",50,18.00f,0.080f,8192.0f,false); }
bool aethermp5_update(aether_weapon_t *w, f32 dt, bool trigger) { aether_weapon_tick(w,dt); return trigger ? aether_weapon_fire(w) : false; }
