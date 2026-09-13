#include "AetherSavePlayer.h"
#include <string.h>
void aethersaveplayer_init(aethersaveplayer_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethersaveplayer_update(aethersaveplayer_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aethersaveplayer_reset(aethersaveplayer_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethersaveplayer_event(aethersaveplayer_state_t*s){if(s)s->events++;}
