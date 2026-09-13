#include "AetherBulletHoles.h"
#include <string.h>
void aetherbulletholes_init(aetherbulletholes_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherbulletholes_update(aetherbulletholes_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherbulletholes_reset(aetherbulletholes_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherbulletholes_event(aetherbulletholes_state_t*s){if(s)s->events++;}
