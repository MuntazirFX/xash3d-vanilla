#include "AetherSplash.h"
#include <string.h>
void aethersplash_init(aethersplash_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethersplash_update(aethersplash_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aethersplash_reset(aethersplash_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethersplash_event(aethersplash_state_t*s){if(s)s->events++;}
