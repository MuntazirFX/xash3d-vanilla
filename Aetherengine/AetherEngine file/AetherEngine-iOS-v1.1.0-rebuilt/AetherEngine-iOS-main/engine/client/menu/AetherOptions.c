#include "AetherOptions.h"
#include <string.h>
void aetheroptions_init(aetheroptions_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetheroptions_update(aetheroptions_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetheroptions_reset(aetheroptions_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetheroptions_event(aetheroptions_state_t*s){if(s)s->events++;}
