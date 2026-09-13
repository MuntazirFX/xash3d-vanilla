#include "AetherObjectives.h"
#include <string.h>
void aetherobjectives_init(aetherobjectives_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherobjectives_update(aetherobjectives_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherobjectives_reset(aetherobjectives_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherobjectives_event(aetherobjectives_state_t*s){if(s)s->events++;}
