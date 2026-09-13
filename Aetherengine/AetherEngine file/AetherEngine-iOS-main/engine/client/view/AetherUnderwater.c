#include "AetherUnderwater.h"
#include <string.h>
void aetherunderwater_init(aetherunderwater_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherunderwater_update(aetherunderwater_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherunderwater_reset(aetherunderwater_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherunderwater_event(aetherunderwater_state_t*s){if(s)s->events++;}
