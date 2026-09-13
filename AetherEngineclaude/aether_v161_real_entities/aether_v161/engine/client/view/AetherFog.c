#include "AetherFog.h"
#include <string.h>
void aetherfog_init(aetherfog_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherfog_update(aetherfog_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherfog_reset(aetherfog_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherfog_event(aetherfog_state_t*s){if(s)s->events++;}
