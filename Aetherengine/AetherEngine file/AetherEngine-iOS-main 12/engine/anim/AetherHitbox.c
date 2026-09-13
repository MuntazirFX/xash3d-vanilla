#include "AetherHitbox.h"
#include <string.h>
void aetherhitbox_init(aetherhitbox_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherhitbox_update(aetherhitbox_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherhitbox_reset(aetherhitbox_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherhitbox_event(aetherhitbox_state_t*s){if(s)s->events++;}
