#include "AetherChapterSelect.h"
#include <string.h>
void aetherchapterselect_init(aetherchapterselect_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherchapterselect_update(aetherchapterselect_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherchapterselect_reset(aetherchapterselect_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherchapterselect_event(aetherchapterselect_state_t*s){if(s)s->events++;}
