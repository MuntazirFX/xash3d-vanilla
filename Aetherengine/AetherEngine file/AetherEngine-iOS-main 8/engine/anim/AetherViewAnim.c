#include "AetherViewAnim.h"
#include <string.h>
void aetherviewanim_init(aetherviewanim_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherviewanim_update(aetherviewanim_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherviewanim_reset(aetherviewanim_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherviewanim_event(aetherviewanim_state_t*s){if(s)s->events++;}
