#include "AetherNavMesh.h"
#include <string.h>
void aethernavmesh_init(aethernavmesh_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethernavmesh_update(aethernavmesh_state_t*s,f32 dt){if(!s||!s->enabled)return;s->value+=dt;}
void aethernavmesh_reset(aethernavmesh_state_t*s){if(s)memset(s,0,sizeof*s),s->enabled=true;}
void aethernavmesh_event(aethernavmesh_state_t*s){if(s)s->events++;}
