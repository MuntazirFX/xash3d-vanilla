#include "AetherViewPunch.h"
#include <string.h>
void aetherviewpunch_init(aetherviewpunch_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherviewpunch_update(aetherviewpunch_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherviewpunch_reset(aetherviewpunch_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherviewpunch_event(aetherviewpunch_state_t*s){if(s)s->events++;}
