#include "AetherWeaponSelect.h"
#include <string.h>
void aetherweaponselect_init(aetherweaponselect_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherweaponselect_update(aetherweaponselect_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherweaponselect_reset(aetherweaponselect_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherweaponselect_event(aetherweaponselect_state_t*s){if(s)s->events++;}
