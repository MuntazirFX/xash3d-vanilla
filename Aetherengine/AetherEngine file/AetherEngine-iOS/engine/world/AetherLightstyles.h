#ifndef AETHER_AETHERLIGHTSTYLES_H
#define AETHER_AETHERLIGHTSTYLES_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherlightstyles_state { bool enabled; f32 value; u32 events; char text[128]; } aetherlightstyles_state_t;
void aetherlightstyles_init(aetherlightstyles_state_t *s);
void aetherlightstyles_update(aetherlightstyles_state_t *s, f32 dt);
void aetherlightstyles_reset(aetherlightstyles_state_t *s);
void aetherlightstyles_event(aetherlightstyles_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
