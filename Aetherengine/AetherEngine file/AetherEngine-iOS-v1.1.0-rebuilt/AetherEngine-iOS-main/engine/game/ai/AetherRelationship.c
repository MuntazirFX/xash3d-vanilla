#include "AetherRelationship.h"
#include <string.h>
void aetherrelationship_init(aetherrelationship_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherrelationship_update(aetherrelationship_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherrelationship_reset(aetherrelationship_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherrelationship_event(aetherrelationship_state_t*s){if(s)s->events++;}
