#include "AetherEnvBeam.h"
#include <string.h>
void aetherenvbeam_init(aetherenvbeam_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherenvbeam_update(aetherenvbeam_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherenvbeam_reset(aetherenvbeam_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherenvbeam_event(aetherenvbeam_state_t*s){if(s)s->events++;}
