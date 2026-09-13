#include "AetherLocalization.h"
#include <string.h>
void aetherlocalization_init(aetherlocalization_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherlocalization_update(aetherlocalization_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherlocalization_reset(aetherlocalization_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherlocalization_event(aetherlocalization_state_t*s){if(s)s->events++;}
