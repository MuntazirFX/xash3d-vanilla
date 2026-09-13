#include "AetherExplosionFX.h"
#include <string.h>
void aetherexplosionfx_init(aetherexplosionfx_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherexplosionfx_update(aetherexplosionfx_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherexplosionfx_reset(aetherexplosionfx_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherexplosionfx_event(aetherexplosionfx_state_t*s){if(s)s->events++;}
