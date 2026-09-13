#include "AetherMonsterSnd.h"
#include <string.h>
void aethermonstersnd_init(aethermonstersnd_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethermonstersnd_update(aethermonstersnd_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aethermonstersnd_reset(aethermonstersnd_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethermonstersnd_event(aethermonstersnd_state_t*s){if(s)s->events++;}
