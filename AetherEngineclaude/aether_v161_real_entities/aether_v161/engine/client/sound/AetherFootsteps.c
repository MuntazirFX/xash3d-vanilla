#include "AetherFootsteps.h"
#include <string.h>
void aetherfootsteps_init(aetherfootsteps_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherfootsteps_update(aetherfootsteps_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherfootsteps_reset(aetherfootsteps_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherfootsteps_event(aetherfootsteps_state_t*s){if(s)s->events++;}
