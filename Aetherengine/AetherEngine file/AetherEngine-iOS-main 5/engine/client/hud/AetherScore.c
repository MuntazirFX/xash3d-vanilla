#include "AetherScore.h"
#include <string.h>
void aetherscore_init(aetherscore_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherscore_update(aetherscore_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherscore_reset(aetherscore_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherscore_event(aetherscore_state_t*s){if(s)s->events++;}
