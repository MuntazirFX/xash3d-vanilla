#ifndef AETHER_AETHERFRUSTUM_H
#define AETHER_AETHERFRUSTUM_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherfrustum_state { bool enabled; f32 value; u32 events; char text[128]; } aetherfrustum_state_t;
void aetherfrustum_init(aetherfrustum_state_t *s);
void aetherfrustum_update(aetherfrustum_state_t *s, f32 dt);
void aetherfrustum_reset(aetherfrustum_state_t *s);
void aetherfrustum_event(aetherfrustum_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
