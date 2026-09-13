#include "AetherArmor.h"
#include <string.h>
void aetherarmor_init(aetherarmor_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherarmor_update(aetherarmor_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherarmor_reset(aetherarmor_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherarmor_event(aetherarmor_state_t*s){if(s)s->events++;}
