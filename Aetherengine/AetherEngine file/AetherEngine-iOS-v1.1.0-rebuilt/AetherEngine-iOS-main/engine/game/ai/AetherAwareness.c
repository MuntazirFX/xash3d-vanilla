#include "AetherAwareness.h"
#include <string.h>
void aetherawareness_init(aetherawareness_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherawareness_update(aetherawareness_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherawareness_reset(aetherawareness_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherawareness_event(aetherawareness_state_t*s){if(s)s->events++;}
