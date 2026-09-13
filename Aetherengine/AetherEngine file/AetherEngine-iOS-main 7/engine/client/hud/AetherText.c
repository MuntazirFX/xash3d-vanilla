#include "AetherText.h"
#include <string.h>
void aethertext_init(aethertext_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethertext_update(aethertext_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aethertext_reset(aethertext_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethertext_event(aethertext_state_t*s){if(s)s->events++;}
