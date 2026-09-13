#include "AetherVOIP.h"
#include <string.h>
void aethervoip_init(aethervoip_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethervoip_update(aethervoip_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aethervoip_reset(aethervoip_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethervoip_event(aethervoip_state_t*s){if(s)s->events++;}
