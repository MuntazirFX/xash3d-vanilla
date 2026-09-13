#include "AetherMenu.h"
#include <string.h>
void aethermenu_init(aethermenu_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethermenu_update(aethermenu_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aethermenu_reset(aethermenu_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethermenu_event(aethermenu_state_t*s){if(s)s->events++;}
