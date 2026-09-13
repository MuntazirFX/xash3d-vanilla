#include "AetherWeaponIcon.h"
#include <string.h>
void aetherweaponicon_init(aetherweaponicon_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherweaponicon_update(aetherweaponicon_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherweaponicon_reset(aetherweaponicon_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherweaponicon_event(aetherweaponicon_state_t*s){if(s)s->events++;}
