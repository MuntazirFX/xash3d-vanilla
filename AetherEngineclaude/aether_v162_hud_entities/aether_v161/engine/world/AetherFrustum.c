#include "AetherFrustum.h"
#include <string.h>
void aetherfrustum_init(aetherfrustum_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherfrustum_update(aetherfrustum_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherfrustum_reset(aetherfrustum_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherfrustum_event(aetherfrustum_state_t*s){if(s)s->events++;}
