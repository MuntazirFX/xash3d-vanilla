#include "AetherAmmo.h"
#include <string.h>
void aetherammo_init(aetherammo_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherammo_update(aetherammo_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherammo_reset(aetherammo_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherammo_event(aetherammo_state_t*s){if(s)s->events++;}
