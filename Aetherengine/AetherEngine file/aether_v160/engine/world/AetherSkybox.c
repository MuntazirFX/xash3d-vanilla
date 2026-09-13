#include "AetherSkybox.h"
#include <string.h>
void aetherskybox_init(aetherskybox_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherskybox_update(aetherskybox_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherskybox_reset(aetherskybox_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherskybox_event(aetherskybox_state_t*s){if(s)s->events++;}
