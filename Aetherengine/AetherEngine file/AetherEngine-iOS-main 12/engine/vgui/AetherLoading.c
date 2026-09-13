#include "AetherLoading.h"
#include <string.h>
void aetherloading_init(aetherloading_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherloading_update(aetherloading_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherloading_reset(aetherloading_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherloading_event(aetherloading_state_t*s){if(s)s->events++;}
