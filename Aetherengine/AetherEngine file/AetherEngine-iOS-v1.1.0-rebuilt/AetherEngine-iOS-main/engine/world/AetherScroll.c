#include "AetherScroll.h"
#include <string.h>
void aetherscroll_init(aetherscroll_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherscroll_update(aetherscroll_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherscroll_reset(aetherscroll_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherscroll_event(aetherscroll_state_t*s){if(s)s->events++;}
