#include "AetherPlayerSync.h"
#include <string.h>
void aetherplayersync_init(aetherplayersync_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherplayersync_update(aetherplayersync_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherplayersync_reset(aetherplayersync_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherplayersync_event(aetherplayersync_state_t*s){if(s)s->events++;}
