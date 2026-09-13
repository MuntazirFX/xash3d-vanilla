#include "AetherBlendSeq.h"
#include <string.h>
void aetherblendseq_init(aetherblendseq_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherblendseq_update(aetherblendseq_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherblendseq_reset(aetherblendseq_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherblendseq_event(aetherblendseq_state_t*s){if(s)s->events++;}
