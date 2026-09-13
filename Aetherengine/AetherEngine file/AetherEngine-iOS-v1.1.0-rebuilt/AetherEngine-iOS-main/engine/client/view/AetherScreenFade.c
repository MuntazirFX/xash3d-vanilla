#include "AetherScreenFade.h"
#include <string.h>
void aetherscreenfade_init(aetherscreenfade_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherscreenfade_update(aetherscreenfade_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherscreenfade_reset(aetherscreenfade_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherscreenfade_event(aetherscreenfade_state_t*s){if(s)s->events++;}
