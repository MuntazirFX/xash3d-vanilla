#include "AetherTrigger.h"
#include <string.h>
void aethertrigger_init(aethertrigger_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethertrigger_update(aethertrigger_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aethertrigger_reset(aethertrigger_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethertrigger_event(aethertrigger_state_t*s){if(s)s->events++;}
