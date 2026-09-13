#include "AetherAmbient.h"
#include <string.h>
void aetherambient_init(aetherambient_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherambient_update(aetherambient_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherambient_reset(aetherambient_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherambient_event(aetherambient_state_t*s){if(s)s->events++;}
