#ifndef AETHER_AETHERNAVMESH_H
#define AETHER_AETHERNAVMESH_H
#include "../../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethernavmesh_state { bool enabled; f32 value; u32 events; char text[128]; } aethernavmesh_state_t;
void aethernavmesh_init(aethernavmesh_state_t *s);
void aethernavmesh_update(aethernavmesh_state_t *s, f32 dt);
void aethernavmesh_reset(aethernavmesh_state_t *s);
void aethernavmesh_event(aethernavmesh_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
