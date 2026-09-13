#include "AetherServerBrowser.h"
#include <string.h>
void aetherserverbrowser_init(aetherserverbrowser_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherserverbrowser_update(aetherserverbrowser_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherserverbrowser_reset(aetherserverbrowser_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherserverbrowser_event(aetherserverbrowser_state_t*s){if(s)s->events++;}
