#include "AetherSaveWeapon.h"
#include <string.h>
void aethersaveweapon_init(aethersaveweapon_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethersaveweapon_update(aethersaveweapon_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aethersaveweapon_reset(aethersaveweapon_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethersaveweapon_event(aethersaveweapon_state_t*s){if(s)s->events++;}
