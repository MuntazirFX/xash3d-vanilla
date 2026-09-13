#include "AetherScoreboard.h"
#include <string.h>
void aetherscoreboard_init(aetherscoreboard_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherscoreboard_update(aetherscoreboard_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherscoreboard_reset(aetherscoreboard_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherscoreboard_event(aetherscoreboard_state_t*s){if(s)s->events++;}
