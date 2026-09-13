#include "AetherSlider.h"
#include <string.h>
void aetherslider_init(aetherslider_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherslider_update(aetherslider_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherslider_reset(aetherslider_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherslider_event(aetherslider_state_t*s){if(s)s->events++;}
