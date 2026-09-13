#include "AetherFuncTrain.h"
#include <string.h>
void aetherfunctrain_init(aetherfunctrain_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherfunctrain_update(aetherfunctrain_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherfunctrain_reset(aetherfunctrain_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherfunctrain_event(aetherfunctrain_state_t*s){if(s)s->events++;}
