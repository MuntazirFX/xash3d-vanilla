#include "AetherDoorSnd.h"
#include <string.h>
void aetherdoorsnd_init(aetherdoorsnd_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherdoorsnd_update(aetherdoorsnd_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherdoorsnd_reset(aetherdoorsnd_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherdoorsnd_event(aetherdoorsnd_state_t*s){if(s)s->events++;}
