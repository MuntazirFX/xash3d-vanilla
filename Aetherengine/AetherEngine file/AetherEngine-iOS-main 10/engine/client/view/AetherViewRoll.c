#include "AetherViewRoll.h"
#include <string.h>
void aetherviewroll_init(aetherviewroll_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherviewroll_update(aetherviewroll_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherviewroll_reset(aetherviewroll_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherviewroll_event(aetherviewroll_state_t*s){if(s)s->events++;}
