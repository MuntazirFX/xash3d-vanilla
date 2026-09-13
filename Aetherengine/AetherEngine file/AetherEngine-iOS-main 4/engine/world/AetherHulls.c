#include "AetherHulls.h"
#include <string.h>
void aetherhulls_init(aetherhulls_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherhulls_update(aetherhulls_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherhulls_reset(aetherhulls_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherhulls_event(aetherhulls_state_t*s){if(s)s->events++;}
