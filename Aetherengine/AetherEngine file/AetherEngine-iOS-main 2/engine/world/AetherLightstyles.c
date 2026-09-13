#include "AetherLightstyles.h"
#include <string.h>
void aetherlightstyles_init(aetherlightstyles_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherlightstyles_update(aetherlightstyles_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherlightstyles_reset(aetherlightstyles_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherlightstyles_event(aetherlightstyles_state_t*s){if(s)s->events++;}
