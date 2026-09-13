#include "AetherGlock.h"
void aether_glock_init(aether_weapon_t*w){aether_weapon_init(w,AETHER_WEAPON_GLOCK,"weapon_9mmhandgun",17,12.0f,0.15f,8192.0f,false);}
bool aether_glock_attack(aether_weapon_t*w){return aether_weapon_fire(w);}
