#include "AetherMuzzleFlash.h"
#include <string.h>
void aethermuzzleflash_init(aethermuzzleflash_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethermuzzleflash_update(aethermuzzleflash_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aethermuzzleflash_reset(aethermuzzleflash_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethermuzzleflash_event(aethermuzzleflash_state_t*s){if(s)s->events++;}
