#ifndef AETHER_AETHERHULLS_H
#define AETHER_AETHERHULLS_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherhulls_state { bool enabled; f32 value; u32 events; char text[128]; } aetherhulls_state_t;
void aetherhulls_init(aetherhulls_state_t *s);
void aetherhulls_update(aetherhulls_state_t *s, f32 dt);
void aetherhulls_reset(aetherhulls_state_t *s);
void aetherhulls_event(aetherhulls_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
