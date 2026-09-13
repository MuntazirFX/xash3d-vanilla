#include "AetherQuickSave.h"
#include <string.h>
void aetherquicksave_init(aetherquicksave_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherquicksave_update(aetherquicksave_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherquicksave_reset(aetherquicksave_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherquicksave_event(aetherquicksave_state_t*s){if(s)s->events++;}
