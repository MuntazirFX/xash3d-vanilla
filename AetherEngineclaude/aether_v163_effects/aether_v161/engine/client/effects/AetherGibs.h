#ifndef AETHER_GIBS_H
#define AETHER_GIBS_H
#include "../../core/AetherCore.h"
#include "../../core/AetherMath.h"
#ifdef __cplusplus
extern "C" {
#endif
#define AETHER_GIBS_MAX 8
typedef struct { aether_vec3_t position, velocity; f32 life; } aether_gib_piece_t;
typedef struct aethergibs_state {
    aether_gib_piece_t pieces[AETHER_GIBS_MAX];
    u32 count;
} aethergibs_state_t;
void aethergibs_init(aethergibs_state_t *s);
/* size_scale: 1.0 = human-sized (headcrab/zombie), higher for big monsters
 * like Gargantua -> more, faster-flying pieces. */
void aethergibs_spawn(aethergibs_state_t *s, aether_vec3_t position, f32 size_scale);
void aethergibs_update(aethergibs_state_t *s, f32 dt);
#ifdef __cplusplus
}
#endif
#endif
