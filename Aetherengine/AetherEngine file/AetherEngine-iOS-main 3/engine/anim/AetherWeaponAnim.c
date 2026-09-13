#include "AetherWeaponAnim.h"
#include <string.h>
void aetherweaponanim_init(aetherweaponanim_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherweaponanim_update(aetherweaponanim_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherweaponanim_reset(aetherweaponanim_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherweaponanim_event(aetherweaponanim_state_t*s){if(s)s->events++;}
