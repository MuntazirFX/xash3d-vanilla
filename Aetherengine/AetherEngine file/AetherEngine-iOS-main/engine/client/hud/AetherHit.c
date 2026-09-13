#include "AetherHit.h"
#include <string.h>
void aetherhit_init(aetherhit_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherhit_update(aetherhit_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherhit_reset(aetherhit_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherhit_event(aetherhit_state_t*s){if(s)s->events++;}
