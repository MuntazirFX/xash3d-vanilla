#include "AetherMultiManager.h"
#include <string.h>
void aethermultimanager_init(aethermultimanager_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethermultimanager_update(aethermultimanager_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aethermultimanager_reset(aethermultimanager_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethermultimanager_event(aethermultimanager_state_t*s){if(s)s->events++;}
