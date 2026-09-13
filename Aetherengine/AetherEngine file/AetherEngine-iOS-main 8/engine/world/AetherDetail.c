#include "AetherDetail.h"
#include <string.h>
void aetherdetail_init(aetherdetail_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherdetail_update(aetherdetail_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherdetail_reset(aetherdetail_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherdetail_event(aetherdetail_state_t*s){if(s)s->events++;}
