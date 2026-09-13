#include "AetherPushable.h"
#include <string.h>
void aetherpushable_init(aetherpushable_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherpushable_update(aetherpushable_state_t*s,f32 dt){if(!s||!s->enabled)return;s->position.x+=s->velocity.x*dt;s->position.y+=s->velocity.y*dt;s->position.z+=s->velocity.z*dt;s->value+=dt;}
void aetherpushable_reset(aetherpushable_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
