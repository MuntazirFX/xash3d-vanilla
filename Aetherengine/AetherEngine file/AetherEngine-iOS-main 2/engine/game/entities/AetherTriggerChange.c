#include "AetherTriggerChange.h"
#include <string.h>
void aethertriggerchange_init(aethertriggerchange_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethertriggerchange_update(aethertriggerchange_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aethertriggerchange_reset(aethertriggerchange_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethertriggerchange_event(aethertriggerchange_state_t*s){if(s)s->events++;}
