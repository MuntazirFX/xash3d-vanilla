#include "AetherTransition.h"
#include <string.h>
void aethertransition_init(aethertransition_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethertransition_update(aethertransition_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aethertransition_reset(aethertransition_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethertransition_event(aethertransition_state_t*s){if(s)s->events++;}
