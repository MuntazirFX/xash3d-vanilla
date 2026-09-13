#include "AetherNewGame.h"
#include <string.h>
void aethernewgame_init(aethernewgame_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethernewgame_update(aethernewgame_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aethernewgame_reset(aethernewgame_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethernewgame_event(aethernewgame_state_t*s){if(s)s->events++;}
