#include "AetherHealth.h"
#include <string.h>
void aetherhealth_init(aetherhealth_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherhealth_update(aetherhealth_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherhealth_reset(aetherhealth_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherhealth_event(aetherhealth_state_t*s){if(s)s->events++;}
