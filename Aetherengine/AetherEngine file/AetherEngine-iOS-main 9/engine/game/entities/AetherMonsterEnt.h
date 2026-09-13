#ifndef AETHER_AETHERMONSTERENT_H
#define AETHER_AETHERMONSTERENT_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethermonsterent_state { bool enabled; f32 value; u32 events; char text[128]; } aethermonsterent_state_t;
void aethermonsterent_init(aethermonsterent_state_t *s);
void aethermonsterent_update(aethermonsterent_state_t *s, f32 dt);
void aethermonsterent_reset(aethermonsterent_state_t *s);
void aethermonsterent_event(aethermonsterent_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
