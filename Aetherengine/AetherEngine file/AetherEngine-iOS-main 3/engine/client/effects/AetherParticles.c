#include "AetherParticles.h"
#include <string.h>
void aetherparticles_init(aetherparticles_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherparticles_update(aetherparticles_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherparticles_reset(aetherparticles_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherparticles_event(aetherparticles_state_t*s){if(s)s->events++;}
