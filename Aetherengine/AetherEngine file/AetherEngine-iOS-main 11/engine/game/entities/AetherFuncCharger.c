#include "AetherFuncCharger.h"
#include <string.h>
void aetherfunccharger_init(aetherfunccharger_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherfunccharger_update(aetherfunccharger_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherfunccharger_reset(aetherfunccharger_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherfunccharger_event(aetherfunccharger_state_t*s){if(s)s->events++;}
