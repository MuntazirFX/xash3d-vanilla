#include "AetherCombat.h"
#include <string.h>
void aethercombat_init(aethercombat_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethercombat_update(aethercombat_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aethercombat_reset(aethercombat_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethercombat_event(aethercombat_state_t*s){if(s)s->events++;}
