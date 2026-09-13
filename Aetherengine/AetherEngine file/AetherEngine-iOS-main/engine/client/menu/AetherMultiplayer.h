#ifndef AETHER_AETHERMULTIPLAYER_H
#define AETHER_AETHERMULTIPLAYER_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethermultiplayer_state { bool enabled; f32 value; u32 events; char text[128]; } aethermultiplayer_state_t;
void aethermultiplayer_init(aethermultiplayer_state_t *s);
void aethermultiplayer_update(aethermultiplayer_state_t *s, f32 dt);
void aethermultiplayer_reset(aethermultiplayer_state_t *s);
void aethermultiplayer_event(aethermultiplayer_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
