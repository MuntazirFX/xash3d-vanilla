#include "AetherBreak.h"
#include <string.h>
void aetherbreak_init(aetherbreak_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherbreak_update(aetherbreak_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherbreak_reset(aetherbreak_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherbreak_event(aetherbreak_state_t*s){if(s)s->events++;}
