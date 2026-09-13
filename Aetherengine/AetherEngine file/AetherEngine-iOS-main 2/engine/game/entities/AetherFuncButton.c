#include "AetherFuncButton.h"
#include <string.h>
void aetherfuncbutton_init(aetherfuncbutton_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherfuncbutton_update(aetherfuncbutton_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherfuncbutton_reset(aetherfuncbutton_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherfuncbutton_event(aetherfuncbutton_state_t*s){if(s)s->events++;}
