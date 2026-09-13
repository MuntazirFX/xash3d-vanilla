#include "AetherPathfind.h"
#include <string.h>
void aetherpathfind_init(aetherpathfind_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherpathfind_update(aetherpathfind_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherpathfind_reset(aetherpathfind_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherpathfind_event(aetherpathfind_state_t*s){if(s)s->events++;}
