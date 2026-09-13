#include "AetherLAN.h"
#include <string.h>
void aetherlan_init(aetherlan_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherlan_update(aetherlan_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherlan_reset(aetherlan_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherlan_event(aetherlan_state_t*s){if(s)s->events++;}
