#include "AetherViewBob.h"
#include <string.h>
void aetherviewbob_init(aetherviewbob_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherviewbob_update(aetherviewbob_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherviewbob_reset(aetherviewbob_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherviewbob_event(aetherviewbob_state_t*s){if(s)s->events++;}
