#include "AetherAABB.h"
#include <string.h>
void aetheraabb_init(aetheraabb_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetheraabb_update(aetheraabb_state_t*s,f32 dt){if(!s||!s->enabled)return;s->position.x+=s->velocity.x*dt;s->position.y+=s->velocity.y*dt;s->position.z+=s->velocity.z*dt;s->value+=dt;}
void aetheraabb_reset(aetheraabb_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
