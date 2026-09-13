#include "AetherMainMenu.h"
#include <string.h>
void aethermainmenu_init(aethermainmenu_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethermainmenu_update(aethermainmenu_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aethermainmenu_reset(aethermainmenu_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethermainmenu_event(aethermainmenu_state_t*s){if(s)s->events++;}
