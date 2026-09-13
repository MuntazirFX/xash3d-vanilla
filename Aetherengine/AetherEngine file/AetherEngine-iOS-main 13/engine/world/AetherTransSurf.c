#include "AetherTransSurf.h"
#include <string.h>
void aethertranssurf_init(aethertranssurf_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethertranssurf_update(aethertranssurf_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aethertranssurf_reset(aethertranssurf_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethertranssurf_event(aethertranssurf_state_t*s){if(s)s->events++;}
