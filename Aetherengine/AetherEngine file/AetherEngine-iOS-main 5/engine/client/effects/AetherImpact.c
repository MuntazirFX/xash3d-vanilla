#include "AetherImpact.h"
#include <string.h>
void aetherimpact_init(aetherimpact_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherimpact_update(aetherimpact_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherimpact_reset(aetherimpact_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherimpact_event(aetherimpact_state_t*s){if(s)s->events++;}
