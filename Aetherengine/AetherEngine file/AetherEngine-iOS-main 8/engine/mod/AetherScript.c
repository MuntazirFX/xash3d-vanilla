#include "AetherScript.h"
#include <string.h>
void aetherscript_init(aetherscript_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherscript_update(aetherscript_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherscript_reset(aetherscript_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherscript_event(aetherscript_state_t*s){if(s)s->events++;}
