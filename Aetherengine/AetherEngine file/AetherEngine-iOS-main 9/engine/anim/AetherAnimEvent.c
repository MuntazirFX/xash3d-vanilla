#include "AetherAnimEvent.h"
#include <string.h>
void aetheranimevent_init(aetheranimevent_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetheranimevent_update(aetheranimevent_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetheranimevent_reset(aetheranimevent_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetheranimevent_event(aetheranimevent_state_t*s){if(s)s->events++;}
