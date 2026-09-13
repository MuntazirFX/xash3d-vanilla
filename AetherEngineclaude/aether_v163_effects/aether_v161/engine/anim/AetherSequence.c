#include "AetherSequence.h"
#include <string.h>
void aethersequence_init(aethersequence_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethersequence_update(aethersequence_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aethersequence_reset(aethersequence_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethersequence_event(aethersequence_state_t*s){if(s)s->events++;}
