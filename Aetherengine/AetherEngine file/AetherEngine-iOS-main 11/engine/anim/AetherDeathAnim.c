#include "AetherDeathAnim.h"
#include <string.h>
void aetherdeathanim_init(aetherdeathanim_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherdeathanim_update(aetherdeathanim_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherdeathanim_reset(aetherdeathanim_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherdeathanim_event(aetherdeathanim_state_t*s){if(s)s->events++;}
