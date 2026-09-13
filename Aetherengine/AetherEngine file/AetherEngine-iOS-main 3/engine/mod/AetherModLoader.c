#include "AetherModLoader.h"
#include <string.h>
void aethermodloader_init(aethermodloader_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethermodloader_update(aethermodloader_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aethermodloader_reset(aethermodloader_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethermodloader_event(aethermodloader_state_t*s){if(s)s->events++;}
