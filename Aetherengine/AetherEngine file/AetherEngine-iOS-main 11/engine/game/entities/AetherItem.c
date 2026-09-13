#include "AetherItem.h"
#include <string.h>
void aetheritem_init(aetheritem_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetheritem_update(aetheritem_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetheritem_reset(aetheritem_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetheritem_event(aetheritem_state_t*s){if(s)s->events++;}
