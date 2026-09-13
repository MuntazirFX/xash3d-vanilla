#ifndef AETHER_AETHERTRACER_H
#define AETHER_AETHERTRACER_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethertracer_state { bool enabled; f32 value; u32 events; char text[128]; } aethertracer_state_t;
void aethertracer_init(aethertracer_state_t *s);
void aethertracer_update(aethertracer_state_t *s, f32 dt);
void aethertracer_reset(aethertracer_state_t *s);
void aethertracer_event(aethertracer_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
