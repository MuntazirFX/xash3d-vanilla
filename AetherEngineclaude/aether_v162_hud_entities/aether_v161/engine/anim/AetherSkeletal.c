#include "AetherSkeletal.h"
#include <string.h>
void aetherskeletal_init(aetherskeletal_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherskeletal_update(aetherskeletal_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherskeletal_reset(aetherskeletal_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherskeletal_event(aetherskeletal_state_t*s){if(s)s->events++;}
