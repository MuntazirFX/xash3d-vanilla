#include "AetherWeaponSync.h"
#include <string.h>
void aetherweaponsync_init(aetherweaponsync_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherweaponsync_update(aetherweaponsync_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherweaponsync_reset(aetherweaponsync_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherweaponsync_event(aetherweaponsync_state_t*s){if(s)s->events++;}
