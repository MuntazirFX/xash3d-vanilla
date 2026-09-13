#include "AetherSaveEntity.h"
#include <string.h>
void aethersaveentity_init(aethersaveentity_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethersaveentity_update(aethersaveentity_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aethersaveentity_reset(aethersaveentity_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethersaveentity_event(aethersaveentity_state_t*s){if(s)s->events++;}
