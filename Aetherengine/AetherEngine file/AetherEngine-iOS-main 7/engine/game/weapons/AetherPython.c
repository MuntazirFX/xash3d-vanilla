#include "AetherPython.h"
void aetherpython_init(aether_weapon_t *w) { aether_weapon_init(w,AETHER_WEAPON_PYTHON,"weapon_python",6,35.00f,0.750f,8192.0f,false); }
bool aetherpython_update(aether_weapon_t *w, f32 dt, bool trigger) { aether_weapon_tick(w,dt); return trigger ? aether_weapon_fire(w) : false; }
