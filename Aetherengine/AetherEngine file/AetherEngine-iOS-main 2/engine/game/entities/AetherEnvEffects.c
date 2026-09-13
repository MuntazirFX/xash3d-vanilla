#include "AetherEnvEffects.h"
#include <string.h>
void aetherenveffects_init(aetherenveffects_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherenveffects_update(aetherenveffects_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherenveffects_reset(aetherenveffects_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherenveffects_event(aetherenveffects_state_t*s){if(s)s->events++;}
