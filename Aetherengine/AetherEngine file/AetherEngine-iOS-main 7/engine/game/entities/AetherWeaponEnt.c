#include "AetherWeaponEnt.h"
#include <string.h>
void aetherweaponent_init(aetherweaponent_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherweaponent_update(aetherweaponent_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherweaponent_reset(aetherweaponent_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherweaponent_event(aetherweaponent_state_t*s){if(s)s->events++;}
