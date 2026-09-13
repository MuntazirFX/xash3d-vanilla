#include "AetherFuncPlat.h"
#include <string.h>
void aetherfuncplat_init(aetherfuncplat_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherfuncplat_update(aetherfuncplat_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherfuncplat_reset(aetherfuncplat_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherfuncplat_event(aetherfuncplat_state_t*s){if(s)s->events++;}
