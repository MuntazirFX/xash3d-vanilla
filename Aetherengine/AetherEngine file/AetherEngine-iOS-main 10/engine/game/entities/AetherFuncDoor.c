#include "AetherFuncDoor.h"
#include <string.h>
void aetherfuncdoor_init(aetherfuncdoor_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherfuncdoor_update(aetherfuncdoor_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherfuncdoor_reset(aetherfuncdoor_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherfuncdoor_event(aetherfuncdoor_state_t*s){if(s)s->events++;}
