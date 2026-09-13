#ifndef AETHER_AETHERPATH_H
#define AETHER_AETHERPATH_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherpath_state { bool enabled; f32 value; u32 events; char text[128]; } aetherpath_state_t;
void aetherpath_init(aetherpath_state_t *s);
void aetherpath_update(aetherpath_state_t *s, f32 dt);
void aetherpath_reset(aetherpath_state_t *s);
void aetherpath_event(aetherpath_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
