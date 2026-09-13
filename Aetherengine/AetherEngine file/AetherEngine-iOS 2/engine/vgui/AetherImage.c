#include "AetherImage.h"
#include <string.h>
void aetherimage_init(aetherimage_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherimage_update(aetherimage_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherimage_reset(aetherimage_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherimage_event(aetherimage_state_t*s){if(s)s->events++;}
