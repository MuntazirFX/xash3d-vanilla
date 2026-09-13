#include "AetherPath.h"
#include <string.h>
void aetherpath_init(aetherpath_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherpath_update(aetherpath_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherpath_reset(aetherpath_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherpath_event(aetherpath_state_t*s){if(s)s->events++;}
