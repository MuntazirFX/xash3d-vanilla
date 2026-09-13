#include "AetherBounce.h"
#include <string.h>
void aetherbounce_init(aetherbounce_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherbounce_update(aetherbounce_state_t*s,f32 dt){if(!s||!s->enabled)return;s->position.x+=s->velocity.x*dt;s->position.y+=s->velocity.y*dt;s->position.z+=s->velocity.z*dt;s->value+=dt;}
void aetherbounce_reset(aetherbounce_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
