#include "AetherSquad.h"
#include <string.h>
void aethersquad_init(aethersquad_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethersquad_update(aethersquad_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aethersquad_reset(aethersquad_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethersquad_event(aethersquad_state_t*s){if(s)s->events++;}
