#include "AetherControlOpts.h"
#include <string.h>
void aethercontrolopts_init(aethercontrolopts_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethercontrolopts_update(aethercontrolopts_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aethercontrolopts_reset(aethercontrolopts_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethercontrolopts_event(aethercontrolopts_state_t*s){if(s)s->events++;}
