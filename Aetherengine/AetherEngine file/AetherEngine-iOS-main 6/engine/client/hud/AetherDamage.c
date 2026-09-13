#include "AetherDamage.h"
#include <string.h>
void aetherdamage_init(aetherdamage_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherdamage_update(aetherdamage_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherdamage_reset(aetherdamage_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherdamage_event(aetherdamage_state_t*s){if(s)s->events++;}
