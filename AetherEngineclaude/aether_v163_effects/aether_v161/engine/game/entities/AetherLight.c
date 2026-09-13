#include "AetherLight.h"
#include <string.h>
void aetherlight_init(aetherlight_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherlight_update(aetherlight_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherlight_reset(aetherlight_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherlight_event(aetherlight_state_t*s){if(s)s->events++;}
