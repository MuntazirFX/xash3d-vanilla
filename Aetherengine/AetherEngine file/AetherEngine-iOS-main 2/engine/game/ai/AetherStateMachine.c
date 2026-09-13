#include "AetherStateMachine.h"
#include <string.h>
void aetherstatemachine_init(aetherstatemachine_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherstatemachine_update(aetherstatemachine_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherstatemachine_reset(aetherstatemachine_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherstatemachine_event(aetherstatemachine_state_t*s){if(s)s->events++;}
