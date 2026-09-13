#include "AetherInfoNode.h"
#include <string.h>
void aetherinfonode_init(aetherinfonode_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherinfonode_update(aetherinfonode_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherinfonode_reset(aetherinfonode_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherinfonode_event(aetherinfonode_state_t*s){if(s)s->events++;}
