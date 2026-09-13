#include "AetherFuncWater.h"
#include <string.h>
void aetherfuncwater_init(aetherfuncwater_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherfuncwater_update(aetherfuncwater_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherfuncwater_reset(aetherfuncwater_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherfuncwater_event(aetherfuncwater_state_t*s){if(s)s->events++;}
