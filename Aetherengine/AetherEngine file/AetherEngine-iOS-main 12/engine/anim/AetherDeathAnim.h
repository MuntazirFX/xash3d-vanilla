#ifndef AETHER_AETHERDEATHANIM_H
#define AETHER_AETHERDEATHANIM_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherdeathanim_state { bool enabled; f32 value; u32 events; char text[128]; } aetherdeathanim_state_t;
void aetherdeathanim_init(aetherdeathanim_state_t *s);
void aetherdeathanim_update(aetherdeathanim_state_t *s, f32 dt);
void aetherdeathanim_reset(aetherdeathanim_state_t *s);
void aetherdeathanim_event(aetherdeathanim_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
