#include "AetherEnvSound.h"
#include <string.h>
void aetherenvsound_init(aetherenvsound_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherenvsound_update(aetherenvsound_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherenvsound_reset(aetherenvsound_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherenvsound_event(aetherenvsound_state_t*s){if(s)s->events++;}
