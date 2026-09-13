#include "AetherExplosion.h"
#include <string.h>
void aetherexplosion_init(aetherexplosion_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherexplosion_update(aetherexplosion_state_t*s,f32 dt){if(!s||!s->enabled)return;s->position.x+=s->velocity.x*dt;s->position.y+=s->velocity.y*dt;s->position.z+=s->velocity.z*dt;s->value+=dt;}
void aetherexplosion_reset(aetherexplosion_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
