#include "AetherFont.h"
#include <string.h>
void aetherfont_init(aetherfont_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherfont_update(aetherfont_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherfont_reset(aetherfont_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherfont_event(aetherfont_state_t*s){if(s)s->events++;}
