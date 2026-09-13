#include "AetherLightning.h"
#include <string.h>
void aetherlightning_init(aetherlightning_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherlightning_update(aetherlightning_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherlightning_reset(aetherlightning_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherlightning_event(aetherlightning_state_t*s){if(s)s->events++;}
