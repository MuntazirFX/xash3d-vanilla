#include "AetherBoneCtrl.h"
#include <string.h>
void aetherbonectrl_init(aetherbonectrl_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherbonectrl_update(aetherbonectrl_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherbonectrl_reset(aetherbonectrl_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherbonectrl_event(aetherbonectrl_state_t*s){if(s)s->events++;}
