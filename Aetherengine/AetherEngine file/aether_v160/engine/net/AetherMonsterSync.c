#include "AetherMonsterSync.h"
#include <string.h>
void aethermonstersync_init(aethermonstersync_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethermonstersync_update(aethermonstersync_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aethermonstersync_reset(aethermonstersync_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethermonstersync_event(aethermonstersync_state_t*s){if(s)s->events++;}
