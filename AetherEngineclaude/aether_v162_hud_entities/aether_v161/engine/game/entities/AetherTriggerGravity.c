#include "AetherTriggerGravity.h"
#include <string.h>
void aethertriggergravity_init(aethertriggergravity_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethertriggergravity_update(aethertriggergravity_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aethertriggergravity_reset(aethertriggergravity_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethertriggergravity_event(aethertriggergravity_state_t*s){if(s)s->events++;}
