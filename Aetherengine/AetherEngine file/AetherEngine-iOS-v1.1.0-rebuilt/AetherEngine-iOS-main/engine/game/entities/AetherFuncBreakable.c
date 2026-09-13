#include "AetherFuncBreakable.h"
#include <string.h>
void aetherfuncbreakable_init(aetherfuncbreakable_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherfuncbreakable_update(aetherfuncbreakable_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherfuncbreakable_reset(aetherfuncbreakable_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherfuncbreakable_event(aetherfuncbreakable_state_t*s){if(s)s->events++;}
