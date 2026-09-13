#ifndef AETHER_AETHERAUTOSAVE_H
#define AETHER_AETHERAUTOSAVE_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherautosave_state { bool enabled; f32 value; u32 events; char text[128]; } aetherautosave_state_t;
void aetherautosave_init(aetherautosave_state_t *s);
void aetherautosave_update(aetherautosave_state_t *s, f32 dt);
void aetherautosave_reset(aetherautosave_state_t *s);
void aetherautosave_event(aetherautosave_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
