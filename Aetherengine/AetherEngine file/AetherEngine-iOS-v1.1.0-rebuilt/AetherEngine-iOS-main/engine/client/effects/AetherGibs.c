#include "AetherGibs.h"
#include <string.h>
void aethergibs_init(aethergibs_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethergibs_update(aethergibs_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aethergibs_reset(aethergibs_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethergibs_event(aethergibs_state_t*s){if(s)s->events++;}
