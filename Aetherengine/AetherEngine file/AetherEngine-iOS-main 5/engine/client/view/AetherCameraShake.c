#include "AetherCameraShake.h"
#include <string.h>
void aethercamerashake_init(aethercamerashake_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethercamerashake_update(aethercamerashake_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aethercamerashake_reset(aethercamerashake_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethercamerashake_event(aethercamerashake_state_t*s){if(s)s->events++;}
