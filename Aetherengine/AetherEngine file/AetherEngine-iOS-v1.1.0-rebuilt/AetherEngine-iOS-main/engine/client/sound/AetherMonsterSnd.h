#ifndef AETHER_AETHERMONSTERSND_H
#define AETHER_AETHERMONSTERSND_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethermonstersnd_state { bool enabled; f32 value; u32 events; char text[128]; } aethermonstersnd_state_t;
void aethermonstersnd_init(aethermonstersnd_state_t *s);
void aethermonstersnd_update(aethermonstersnd_state_t *s, f32 dt);
void aethermonstersnd_reset(aethermonstersnd_state_t *s);
void aethermonstersnd_event(aethermonstersnd_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
