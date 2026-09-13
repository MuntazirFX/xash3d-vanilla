#include "AetherSparks.h"
#include <string.h>
void aethersparks_init(aethersparks_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethersparks_update(aethersparks_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aethersparks_reset(aethersparks_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethersparks_event(aethersparks_state_t*s){if(s)s->events++;}
