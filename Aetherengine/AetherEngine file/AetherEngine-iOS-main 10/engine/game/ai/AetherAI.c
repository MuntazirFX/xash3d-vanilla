#include "AetherAI.h"
#include <string.h>
void aetherai_init(aetherai_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherai_update(aetherai_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherai_reset(aetherai_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherai_event(aetherai_state_t*s){if(s)s->events++;}
