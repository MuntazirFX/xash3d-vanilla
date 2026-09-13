#include "AetherHLSDK.h"
#include <string.h>
void aetherhlsdk_init(aetherhlsdk_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherhlsdk_update(aetherhlsdk_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherhlsdk_reset(aetherhlsdk_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherhlsdk_event(aetherhlsdk_state_t*s){if(s)s->events++;}
