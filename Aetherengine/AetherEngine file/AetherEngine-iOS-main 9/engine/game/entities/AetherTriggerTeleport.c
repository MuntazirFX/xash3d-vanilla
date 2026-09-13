#include "AetherTriggerTeleport.h"
#include <string.h>
void aethertriggerteleport_init(aethertriggerteleport_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethertriggerteleport_update(aethertriggerteleport_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aethertriggerteleport_reset(aethertriggerteleport_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethertriggerteleport_event(aethertriggerteleport_state_t*s){if(s)s->events++;}
