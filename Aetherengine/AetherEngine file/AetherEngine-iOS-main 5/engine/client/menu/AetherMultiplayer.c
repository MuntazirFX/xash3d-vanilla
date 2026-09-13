#include "AetherMultiplayer.h"
#include <string.h>
void aethermultiplayer_init(aethermultiplayer_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethermultiplayer_update(aethermultiplayer_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aethermultiplayer_reset(aethermultiplayer_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethermultiplayer_event(aethermultiplayer_state_t*s){if(s)s->events++;}
