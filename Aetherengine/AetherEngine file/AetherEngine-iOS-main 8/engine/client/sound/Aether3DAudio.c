#include "Aether3DAudio.h"
#include <string.h>
void aether3daudio_init(aether3daudio_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aether3daudio_update(aether3daudio_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aether3daudio_reset(aether3daudio_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aether3daudio_event(aether3daudio_state_t*s){if(s)s->events++;}
