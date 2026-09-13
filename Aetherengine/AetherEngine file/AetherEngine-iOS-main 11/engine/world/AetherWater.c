#include "AetherWater.h"
#include <string.h>
void aetherwater_init(aetherwater_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherwater_update(aetherwater_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherwater_reset(aetherwater_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherwater_event(aetherwater_state_t*s){if(s)s->events++;}
