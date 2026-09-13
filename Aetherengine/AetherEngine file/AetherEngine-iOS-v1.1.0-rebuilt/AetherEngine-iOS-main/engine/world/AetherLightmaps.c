#include "AetherLightmaps.h"
#include <string.h>
void aetherlightmaps_init(aetherlightmaps_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherlightmaps_update(aetherlightmaps_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherlightmaps_reset(aetherlightmaps_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherlightmaps_event(aetherlightmaps_state_t*s){if(s)s->events++;}
