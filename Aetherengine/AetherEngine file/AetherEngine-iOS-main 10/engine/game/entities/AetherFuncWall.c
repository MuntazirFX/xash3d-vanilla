#include "AetherFuncWall.h"
#include <string.h>
void aetherfuncwall_init(aetherfuncwall_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherfuncwall_update(aetherfuncwall_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherfuncwall_reset(aetherfuncwall_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherfuncwall_event(aetherfuncwall_state_t*s){if(s)s->events++;}
