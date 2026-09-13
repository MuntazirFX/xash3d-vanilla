#include "AetherScriptedSeq.h"
#include <string.h>
void aetherscriptedseq_init(aetherscriptedseq_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherscriptedseq_update(aetherscriptedseq_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aetherscriptedseq_reset(aetherscriptedseq_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aetherscriptedseq_event(aetherscriptedseq_state_t*s){if(s)s->events++;}
