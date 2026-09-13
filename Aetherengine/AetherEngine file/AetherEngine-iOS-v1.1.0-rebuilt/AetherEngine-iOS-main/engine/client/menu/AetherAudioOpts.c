#include "AetherAudioOpts.h"
#include <string.h>
void aetheraudioopts_init(aetheraudioopts_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetheraudioopts_update(aetheraudioopts_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetheraudioopts_reset(aetheraudioopts_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetheraudioopts_event(aetheraudioopts_state_t*s){if(s)s->events++;}
