#include "AetherSky.h"
#include <string.h>
void aethersky_init(aethersky_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethersky_update(aethersky_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aethersky_reset(aethersky_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethersky_event(aethersky_state_t*s){if(s)s->events++;}
