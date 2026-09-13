#include "AetherChat.h"
#include <string.h>
void aetherchat_init(aetherchat_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherchat_update(aetherchat_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherchat_reset(aetherchat_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherchat_event(aetherchat_state_t*s){if(s)s->events++;}
