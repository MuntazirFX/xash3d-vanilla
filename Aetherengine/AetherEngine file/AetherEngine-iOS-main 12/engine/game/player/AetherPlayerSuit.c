#include "AetherPlayerSuit.h"
#include <string.h>
void aetherplayersuit_init(aetherplayersuit_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherplayersuit_update(aetherplayersuit_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherplayersuit_reset(aetherplayersuit_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherplayersuit_event(aetherplayersuit_state_t*s){if(s)s->events++;}
