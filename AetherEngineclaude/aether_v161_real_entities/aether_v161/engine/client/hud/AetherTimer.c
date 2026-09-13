#include "AetherTimer.h"
#include <string.h>
void aethertimer_init(aethertimer_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethertimer_update(aethertimer_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aethertimer_reset(aethertimer_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethertimer_event(aethertimer_state_t*s){if(s)s->events++;}
