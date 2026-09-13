#include "AetherSmoke.h"
#include <string.h>
void aethersmoke_init(aethersmoke_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethersmoke_update(aethersmoke_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aethersmoke_reset(aethersmoke_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethersmoke_event(aethersmoke_state_t*s){if(s)s->events++;}
