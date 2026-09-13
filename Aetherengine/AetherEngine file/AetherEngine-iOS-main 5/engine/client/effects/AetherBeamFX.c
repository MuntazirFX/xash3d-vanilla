#include "AetherBeamFX.h"
#include <string.h>
void aetherbeamfx_init(aetherbeamfx_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherbeamfx_update(aetherbeamfx_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherbeamfx_reset(aetherbeamfx_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherbeamfx_event(aetherbeamfx_state_t*s){if(s)s->events++;}
