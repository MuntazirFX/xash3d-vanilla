#include "AetherMonsterEnt.h"
#include <string.h>
void aethermonsterent_init(aethermonsterent_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethermonsterent_update(aethermonsterent_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aethermonsterent_reset(aethermonsterent_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethermonsterent_event(aethermonsterent_state_t*s){if(s)s->events++;}
