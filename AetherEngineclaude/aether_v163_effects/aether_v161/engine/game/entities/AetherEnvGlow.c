#include "AetherEnvGlow.h"
#include <string.h>
void aetherenvglow_init(aetherenvglow_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherenvglow_update(aetherenvglow_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherenvglow_reset(aetherenvglow_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherenvglow_event(aetherenvglow_state_t*s){if(s)s->events++;}
