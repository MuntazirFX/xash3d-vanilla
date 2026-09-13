#include "AetherLoadSave.h"
#include <string.h>
void aetherloadsave_init(aetherloadsave_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherloadsave_update(aetherloadsave_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherloadsave_reset(aetherloadsave_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherloadsave_event(aetherloadsave_state_t*s){if(s)s->events++;}
