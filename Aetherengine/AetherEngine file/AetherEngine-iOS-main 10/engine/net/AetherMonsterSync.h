#ifndef AETHER_AETHERMONSTERSYNC_H
#define AETHER_AETHERMONSTERSYNC_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethermonstersync_state { bool enabled; f32 value; u32 events; char text[128]; } aethermonstersync_state_t;
void aethermonstersync_init(aethermonstersync_state_t *s);
void aethermonstersync_update(aethermonstersync_state_t *s, f32 dt);
void aethermonstersync_reset(aethermonstersync_state_t *s);
void aethermonstersync_event(aethermonstersync_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
