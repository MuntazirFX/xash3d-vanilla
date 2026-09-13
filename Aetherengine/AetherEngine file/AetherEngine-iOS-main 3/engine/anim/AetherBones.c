#include "AetherBones.h"
#include <string.h>
void aetherbones_init(aetherbones_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherbones_update(aetherbones_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherbones_reset(aetherbones_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherbones_event(aetherbones_state_t*s){if(s)s->events++;}
