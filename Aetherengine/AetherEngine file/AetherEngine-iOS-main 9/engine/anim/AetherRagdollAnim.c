#include "AetherRagdollAnim.h"
#include <string.h>
void aetherragdollanim_init(aetherragdollanim_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherragdollanim_update(aetherragdollanim_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherragdollanim_reset(aetherragdollanim_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherragdollanim_event(aetherragdollanim_state_t*s){if(s)s->events++;}
