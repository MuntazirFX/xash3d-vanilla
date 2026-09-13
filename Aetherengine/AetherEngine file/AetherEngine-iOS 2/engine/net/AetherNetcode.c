#include "AetherNetcode.h"
#include <string.h>
void aethernetcode_init(aethernetcode_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethernetcode_update(aethernetcode_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aethernetcode_reset(aethernetcode_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethernetcode_event(aethernetcode_state_t*s){if(s)s->events++;}
