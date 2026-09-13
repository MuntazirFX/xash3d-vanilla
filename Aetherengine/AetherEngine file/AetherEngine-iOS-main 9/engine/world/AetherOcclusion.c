#include "AetherOcclusion.h"
#include <string.h>
void aetherocclusion_init(aetherocclusion_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherocclusion_update(aetherocclusion_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherocclusion_reset(aetherocclusion_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherocclusion_event(aetherocclusion_state_t*s){if(s)s->events++;}
