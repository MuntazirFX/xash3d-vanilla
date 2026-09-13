#include "AetherSaveMonster.h"
#include <string.h>
void aethersavemonster_init(aethersavemonster_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethersavemonster_update(aethersavemonster_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aethersavemonster_reset(aethersavemonster_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethersavemonster_event(aethersavemonster_state_t*s){if(s)s->events++;}
