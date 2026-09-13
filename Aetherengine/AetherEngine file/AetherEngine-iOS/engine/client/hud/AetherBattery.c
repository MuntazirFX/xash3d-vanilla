#include "AetherBattery.h"
#include <string.h>
void aetherbattery_init(aetherbattery_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherbattery_update(aetherbattery_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherbattery_reset(aetherbattery_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherbattery_event(aetherbattery_state_t*s){if(s)s->events++;}
