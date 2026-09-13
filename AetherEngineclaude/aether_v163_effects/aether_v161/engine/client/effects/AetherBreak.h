#ifndef AETHER_BREAK_H
#define AETHER_BREAK_H
#include "../../core/AetherCore.h"
#include "../../core/AetherMath.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef enum { AETHER_BREAK_GLASS = 0, AETHER_BREAK_WOOD, AETHER_BREAK_METAL } aether_break_material_t;
#define AETHER_BREAK_MAX_PIECES 10
typedef struct { aether_vec3_t position, velocity; f32 life; } aether_break_piece_t;
typedef struct aetherbreak_state {
    aether_break_piece_t pieces[AETHER_BREAK_MAX_PIECES];
    u32 count;
    aether_break_material_t material;
} aetherbreak_state_t;
void aetherbreak_init(aetherbreak_state_t *s);
void aetherbreak_shatter(aetherbreak_state_t *s, aether_vec3_t position, aether_break_material_t material);
void aetherbreak_update(aetherbreak_state_t *s, f32 dt);
#ifdef __cplusplus
}
#endif
#endif
