#include "AetherPlayerLadder.h"
#include <string.h>
void aetherplayerladder_init(aetherplayerladder_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherplayerladder_update(aetherplayerladder_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherplayerladder_reset(aetherplayerladder_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherplayerladder_event(aetherplayerladder_state_t*s){if(s)s->events++;}
