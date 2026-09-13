#include "AetherFuncPushable.h"
#include <string.h>
void aetherfuncpushable_init(aetherfuncpushable_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherfuncpushable_update(aetherfuncpushable_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherfuncpushable_reset(aetherfuncpushable_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherfuncpushable_event(aetherfuncpushable_state_t*s){if(s)s->events++;}
