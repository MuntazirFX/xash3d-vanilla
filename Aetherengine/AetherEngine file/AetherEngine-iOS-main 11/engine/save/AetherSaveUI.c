#include "AetherSaveUI.h"
#include <string.h>
void aethersaveui_init(aethersaveui_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethersaveui_update(aethersaveui_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aethersaveui_reset(aethersaveui_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethersaveui_event(aethersaveui_state_t*s){if(s)s->events++;}
