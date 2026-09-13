#include "AetherGameRules.h"
#include <string.h>
void aethergamerules_init(aethergamerules_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethergamerules_update(aethergamerules_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aethergamerules_reset(aethergamerules_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethergamerules_event(aethergamerules_state_t*s){if(s)s->events++;}
