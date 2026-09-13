#include "AetherConsole.h"
#include <string.h>
void aetherconsole_init(aetherconsole_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherconsole_update(aetherconsole_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherconsole_reset(aetherconsole_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherconsole_event(aetherconsole_state_t*s){if(s)s->events++;}
