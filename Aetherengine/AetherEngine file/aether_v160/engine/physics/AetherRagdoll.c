#include "AetherRagdoll.h"
#include <string.h>
void aetherragdoll_init(aetherragdoll_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherragdoll_update(aetherragdoll_state_t*s,f32 dt){if(!s||!s->enabled)return;s->position.x+=s->velocity.x*dt;s->position.y+=s->velocity.y*dt;s->position.z+=s->velocity.z*dt;s->value+=dt;}
void aetherragdoll_reset(aetherragdoll_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
