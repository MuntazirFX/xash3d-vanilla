#ifndef AETHER_AETHERSAVEPLAYER_H
#define AETHER_AETHERSAVEPLAYER_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethersaveplayer_state { bool enabled; f32 value; u32 events; char text[128]; } aethersaveplayer_state_t;
void aethersaveplayer_init(aethersaveplayer_state_t *s);
void aethersaveplayer_update(aethersaveplayer_state_t *s, f32 dt);
void aethersaveplayer_reset(aethersaveplayer_state_t *s);
void aethersaveplayer_event(aethersaveplayer_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
