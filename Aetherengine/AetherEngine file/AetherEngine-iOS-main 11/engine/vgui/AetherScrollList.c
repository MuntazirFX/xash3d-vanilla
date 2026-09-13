#include "AetherScrollList.h"
#include <string.h>
void aetherscrolllist_init(aetherscrolllist_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherscrolllist_update(aetherscrolllist_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherscrolllist_reset(aetherscrolllist_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherscrolllist_event(aetherscrolllist_state_t*s){if(s)s->events++;}
