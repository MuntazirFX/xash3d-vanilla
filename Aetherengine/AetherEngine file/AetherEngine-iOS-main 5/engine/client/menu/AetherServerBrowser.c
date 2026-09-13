#include "AetherServerBrowser.h"
#include <string.h>
void aether_menu_server_browser_init(aether_menu_server_browser_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aether_menu_server_browser_update(aether_menu_server_browser_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aether_menu_server_browser_reset(aether_menu_server_browser_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aether_menu_server_browser_event(aether_menu_server_browser_state_t*s){if(s)s->events++;}
