#include "AetherTextInput.h"
#include <string.h>
void aethertextinput_init(aethertextinput_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethertextinput_update(aethertextinput_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aethertextinput_reset(aethertextinput_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethertextinput_event(aethertextinput_state_t*s){if(s)s->events++;}
