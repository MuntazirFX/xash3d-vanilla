#include "AetherMasterServer.h"
#include <string.h>
void aethermasterserver_init(aethermasterserver_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethermasterserver_update(aethermasterserver_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aethermasterserver_reset(aethermasterserver_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethermasterserver_event(aethermasterserver_state_t*s){if(s)s->events++;}
