#include "AetherMusic.h"
#include <string.h>
void aethermusic_init(aethermusic_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethermusic_update(aethermusic_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aethermusic_reset(aethermusic_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethermusic_event(aethermusic_state_t*s){if(s)s->events++;}
