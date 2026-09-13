#include "AetherEnvFade.h"
#include <string.h>
void aetherenvfade_init(aetherenvfade_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherenvfade_update(aetherenvfade_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherenvfade_reset(aetherenvfade_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherenvfade_event(aetherenvfade_state_t*s){if(s)s->events++;}
