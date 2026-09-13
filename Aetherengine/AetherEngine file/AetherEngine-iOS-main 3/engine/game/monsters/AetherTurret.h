#ifndef AETHER_AETHERTURRET_H
#define AETHER_AETHERTURRET_H
#include "AetherMonsterBase.h"
#ifdef __cplusplus
extern "C" {
#endif
void aetherturret_init(aether_monster_t *m, u32 id, aether_vec3_t position);
void aetherturret_update(aether_monster_t *m, aether_vec3_t target, f32 dt);
#ifdef __cplusplus
}
#endif
#endif
