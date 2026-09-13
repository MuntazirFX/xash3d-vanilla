#include "AetherFuncTank.h"
#include <string.h>
void aetherfunctank_init(aetherfunctank_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherfunctank_update(aetherfunctank_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherfunctank_reset(aetherfunctank_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherfunctank_event(aetherfunctank_state_t*s){if(s)s->events++;}
