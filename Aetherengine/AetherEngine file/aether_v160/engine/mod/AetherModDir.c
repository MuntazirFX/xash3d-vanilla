#include "AetherModDir.h"
#include <string.h>
void aethermoddir_init(aethermoddir_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethermoddir_update(aethermoddir_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aethermoddir_reset(aethermoddir_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethermoddir_event(aethermoddir_state_t*s){if(s)s->events++;}
