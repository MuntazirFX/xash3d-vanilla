#ifndef AETHER_AETHERMUSIC_H
#define AETHER_AETHERMUSIC_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethermusic_state { bool enabled; f32 value; u32 events; char text[128]; } aethermusic_state_t;
void aethermusic_init(aethermusic_state_t *s);
void aethermusic_update(aethermusic_state_t *s, f32 dt);
void aethermusic_reset(aethermusic_state_t *s);
void aethermusic_event(aethermusic_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
