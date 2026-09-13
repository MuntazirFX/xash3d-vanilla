#ifndef AETHER_AETHERRAGDOLL_H
#define AETHER_AETHERRAGDOLL_H
#include "../core/AetherCore.h"
#include "../core/AetherMath.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherragdoll_state { bool enabled; f32 value; aether_vec3_t position,velocity; } aetherragdoll_state_t;
void aetherragdoll_init(aetherragdoll_state_t *s);
void aetherragdoll_update(aetherragdoll_state_t *s, f32 dt);
void aetherragdoll_reset(aetherragdoll_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
