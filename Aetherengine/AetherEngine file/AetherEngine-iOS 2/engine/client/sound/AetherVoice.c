#include "AetherVoice.h"
#include <string.h>
void aethervoice_init(aethervoice_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethervoice_update(aethervoice_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aethervoice_reset(aethervoice_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethervoice_event(aethervoice_state_t*s){if(s)s->events++;}
