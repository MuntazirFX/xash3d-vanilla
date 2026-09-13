#include "AetherSaveWorld.h"
#include <string.h>
void aethersaveworld_init(aethersaveworld_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethersaveworld_update(aethersaveworld_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aethersaveworld_reset(aethersaveworld_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethersaveworld_event(aethersaveworld_state_t*s){if(s)s->events++;}
