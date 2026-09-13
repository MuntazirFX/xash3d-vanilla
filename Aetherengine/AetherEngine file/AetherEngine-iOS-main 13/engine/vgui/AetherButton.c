#include "AetherButton.h"
#include <string.h>
void aetherbutton_init(aetherbutton_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherbutton_update(aetherbutton_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherbutton_reset(aetherbutton_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherbutton_event(aetherbutton_state_t*s){if(s)s->events++;}
