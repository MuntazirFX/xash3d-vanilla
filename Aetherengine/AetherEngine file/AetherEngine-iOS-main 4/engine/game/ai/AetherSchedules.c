#include "AetherSchedules.h"
#include <string.h>
void aetherschedules_init(aetherschedules_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherschedules_update(aetherschedules_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherschedules_reset(aetherschedules_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherschedules_event(aetherschedules_state_t*s){if(s)s->events++;}
