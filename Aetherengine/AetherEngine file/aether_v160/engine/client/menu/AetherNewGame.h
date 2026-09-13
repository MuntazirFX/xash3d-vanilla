#ifndef AETHER_AETHERNEWGAME_H
#define AETHER_AETHERNEWGAME_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethernewgame_state { bool enabled; f32 value; u32 events; char text[128]; } aethernewgame_state_t;
void aethernewgame_init(aethernewgame_state_t *s);
void aethernewgame_update(aethernewgame_state_t *s, f32 dt);
void aethernewgame_reset(aethernewgame_state_t *s);
void aethernewgame_event(aethernewgame_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
