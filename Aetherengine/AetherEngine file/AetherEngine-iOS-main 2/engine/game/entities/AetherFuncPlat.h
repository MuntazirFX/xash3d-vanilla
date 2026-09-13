#ifndef AETHER_AETHERFUNCPLAT_H
#define AETHER_AETHERFUNCPLAT_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherfuncplat_state { bool enabled; f32 value; u32 events; char text[128]; } aetherfuncplat_state_t;
void aetherfuncplat_init(aetherfuncplat_state_t *s);
void aetherfuncplat_update(aetherfuncplat_state_t *s, f32 dt);
void aetherfuncplat_reset(aetherfuncplat_state_t *s);
void aetherfuncplat_event(aetherfuncplat_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
