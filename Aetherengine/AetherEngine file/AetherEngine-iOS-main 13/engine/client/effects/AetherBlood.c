#include "AetherBlood.h"
#include <string.h>
void aetherblood_init(aetherblood_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherblood_update(aetherblood_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherblood_reset(aetherblood_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherblood_event(aetherblood_state_t*s){if(s)s->events++;}
