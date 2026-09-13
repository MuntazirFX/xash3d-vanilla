#ifndef AETHER_AETHERHUMANSERGEANT_H
#define AETHER_AETHERHUMANSERGEANT_H
#include "AetherMonsterBase.h"
#ifdef __cplusplus
extern "C" {
#endif
void aetherhumansergeant_init(aether_monster_t *m, u32 id, aether_vec3_t position);
void aetherhumansergeant_update(aether_monster_t *m, aether_vec3_t target, f32 dt);
#ifdef __cplusplus
}
#endif
#endif
