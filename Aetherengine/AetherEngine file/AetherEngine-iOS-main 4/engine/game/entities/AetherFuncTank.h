#ifndef AETHER_AETHERFUNCTANK_H
#define AETHER_AETHERFUNCTANK_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherfunctank_state { bool enabled; f32 value; u32 events; char text[128]; } aetherfunctank_state_t;
void aetherfunctank_init(aetherfunctank_state_t *s);
void aetherfunctank_update(aetherfunctank_state_t *s, f32 dt);
void aetherfunctank_reset(aetherfunctank_state_t *s);
void aetherfunctank_event(aetherfunctank_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
