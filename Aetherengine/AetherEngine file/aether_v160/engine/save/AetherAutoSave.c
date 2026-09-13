#include "AetherAutoSave.h"
#include <string.h>
void aetherautosave_init(aetherautosave_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherautosave_update(aetherautosave_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherautosave_reset(aetherautosave_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherautosave_event(aetherautosave_state_t*s){if(s)s->events++;}
