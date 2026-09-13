#include "AetherCrowbar.h"
void aether_crowbar_init(aether_weapon_t*w){aether_weapon_init(w,AETHER_WEAPON_CROWBAR,"weapon_crowbar",1,25.0f,0.45f,64.0f,false);}
bool aether_crowbar_attack(aether_weapon_t*w){return aether_weapon_fire(w);}
