#include "AetherLadders.h"
#include <string.h>
void aetherladders_init(aetherladders_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherladders_update(aetherladders_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherladders_reset(aetherladders_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherladders_event(aetherladders_state_t*s){if(s)s->events++;}
