#include "AetherBlending.h"
#include <string.h>
void aetherblending_init(aetherblending_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherblending_update(aetherblending_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherblending_reset(aetherblending_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherblending_event(aetherblending_state_t*s){if(s)s->events++;}
