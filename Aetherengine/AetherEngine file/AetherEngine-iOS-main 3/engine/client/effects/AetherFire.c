#include "AetherFire.h"
#include <string.h>
void aetherfire_init(aetherfire_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherfire_update(aetherfire_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherfire_reset(aetherfire_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherfire_event(aetherfire_state_t*s){if(s)s->events++;}
