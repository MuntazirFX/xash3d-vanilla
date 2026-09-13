#ifndef AETHER_AETHERCAMERASHAKE_H
#define AETHER_AETHERCAMERASHAKE_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethercamerashake_state { bool enabled; f32 value; u32 events; char text[128]; } aethercamerashake_state_t;
void aethercamerashake_init(aethercamerashake_state_t *s);
void aethercamerashake_update(aethercamerashake_state_t *s, f32 dt);
void aethercamerashake_reset(aethercamerashake_state_t *s);
void aethercamerashake_event(aethercamerashake_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
