#include "AetherCustomAssets.h"
#include <string.h>
void aethercustomassets_init(aethercustomassets_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethercustomassets_update(aethercustomassets_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aethercustomassets_reset(aethercustomassets_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethercustomassets_event(aethercustomassets_state_t*s){if(s)s->events++;}
