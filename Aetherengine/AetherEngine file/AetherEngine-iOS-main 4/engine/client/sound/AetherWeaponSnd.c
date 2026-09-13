#include "AetherWeaponSnd.h"
#include <string.h>
void aetherweaponsnd_init(aetherweaponsnd_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherweaponsnd_update(aetherweaponsnd_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherweaponsnd_reset(aetherweaponsnd_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherweaponsnd_event(aetherweaponsnd_state_t*s){if(s)s->events++;}
