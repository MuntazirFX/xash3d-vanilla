#include "AetherTexAnim.h"
#include <string.h>
void aethertexanim_init(aethertexanim_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethertexanim_update(aethertexanim_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aethertexanim_reset(aethertexanim_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethertexanim_event(aethertexanim_state_t*s){if(s)s->events++;}
