#include "AetherTracer.h"
#include <string.h>
void aethertracer_init(aethertracer_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethertracer_update(aethertracer_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aethertracer_reset(aethertracer_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethertracer_event(aethertracer_state_t*s){if(s)s->events++;}
