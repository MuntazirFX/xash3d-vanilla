#include "AetherDedicated.h"
#include <string.h>
void aetherdedicated_init(aetherdedicated_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherdedicated_update(aetherdedicated_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherdedicated_reset(aetherdedicated_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherdedicated_event(aetherdedicated_state_t*s){if(s)s->events++;}
