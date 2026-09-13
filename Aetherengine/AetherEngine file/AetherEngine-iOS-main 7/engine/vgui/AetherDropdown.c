#include "AetherDropdown.h"
#include <string.h>
void aetherdropdown_init(aetherdropdown_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherdropdown_update(aetherdropdown_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherdropdown_reset(aetherdropdown_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherdropdown_event(aetherdropdown_state_t*s){if(s)s->events++;}
