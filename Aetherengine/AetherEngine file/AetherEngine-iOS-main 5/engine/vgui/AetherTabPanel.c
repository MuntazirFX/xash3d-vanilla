#include "AetherTabPanel.h"
#include <string.h>
void aethertabpanel_init(aethertabpanel_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethertabpanel_update(aethertabpanel_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aethertabpanel_reset(aethertabpanel_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethertabpanel_event(aethertabpanel_state_t*s){if(s)s->events++;}
