#ifndef AETHER_AETHERLIGHTMAPS_H
#define AETHER_AETHERLIGHTMAPS_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherlightmaps_state { bool enabled; f32 value; u32 events; char text[128]; } aetherlightmaps_state_t;
void aetherlightmaps_init(aetherlightmaps_state_t *s);
void aetherlightmaps_update(aetherlightmaps_state_t *s, f32 dt);
void aetherlightmaps_reset(aetherlightmaps_state_t *s);
void aetherlightmaps_event(aetherlightmaps_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
