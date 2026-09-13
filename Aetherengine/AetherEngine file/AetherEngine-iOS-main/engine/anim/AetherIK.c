#include "AetherIK.h"
#include <string.h>
void aetherik_init(aetherik_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherik_update(aetherik_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherik_reset(aetherik_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherik_event(aetherik_state_t*s){if(s)s->events++;}
