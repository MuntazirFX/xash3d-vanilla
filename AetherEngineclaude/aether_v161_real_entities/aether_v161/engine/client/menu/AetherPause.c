#include "AetherPause.h"
#include <string.h>
void aetherpause_init(aetherpause_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherpause_update(aetherpause_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherpause_reset(aetherpause_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherpause_event(aetherpause_state_t*s){if(s)s->events++;}
