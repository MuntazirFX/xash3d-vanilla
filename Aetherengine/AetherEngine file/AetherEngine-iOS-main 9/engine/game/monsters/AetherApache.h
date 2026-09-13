#ifndef AETHER_AETHERAPACHE_H
#define AETHER_AETHERAPACHE_H
#include "AetherMonsterBase.h"
#ifdef __cplusplus
extern "C" {
#endif
void aetherapache_init(aether_monster_t *m, u32 id, aether_vec3_t position);
void aetherapache_update(aether_monster_t *m, aether_vec3_t target, f32 dt);
#ifdef __cplusplus
}
#endif
#endif
