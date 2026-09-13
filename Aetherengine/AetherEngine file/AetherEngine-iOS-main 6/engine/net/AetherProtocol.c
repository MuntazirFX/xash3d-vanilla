#include "AetherProtocol.h"
#include <string.h>
void aetherprotocol_init(aetherprotocol_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherprotocol_update(aetherprotocol_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherprotocol_reset(aetherprotocol_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherprotocol_event(aetherprotocol_state_t*s){if(s)s->events++;}
