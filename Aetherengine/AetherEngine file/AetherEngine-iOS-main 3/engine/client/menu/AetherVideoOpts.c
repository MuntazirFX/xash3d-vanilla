#include "AetherVideoOpts.h"
#include <string.h>
void aethervideoopts_init(aethervideoopts_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethervideoopts_update(aethervideoopts_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aethervideoopts_reset(aethervideoopts_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethervideoopts_event(aethervideoopts_state_t*s){if(s)s->events++;}
