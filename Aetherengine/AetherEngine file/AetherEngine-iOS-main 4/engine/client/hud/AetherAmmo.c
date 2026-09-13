#include "AetherAmmo.h"
#include <string.h>
void aether_hud_ammo_init(aether_hud_ammo_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aether_hud_ammo_update(aether_hud_ammo_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aether_hud_ammo_reset(aether_hud_ammo_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aether_hud_ammo_event(aether_hud_ammo_state_t*s){if(s)s->events++;}
