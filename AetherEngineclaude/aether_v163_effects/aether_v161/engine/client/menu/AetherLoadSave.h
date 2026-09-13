#ifndef AETHER_AETHERLOADSAVE_H
#define AETHER_AETHERLOADSAVE_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherloadsave_state { bool enabled; f32 value; u32 events; char text[128]; } aetherloadsave_state_t;
void aetherloadsave_init(aetherloadsave_state_t *s);
void aetherloadsave_update(aetherloadsave_state_t *s, f32 dt);
void aetherloadsave_reset(aetherloadsave_state_t *s);
void aetherloadsave_event(aetherloadsave_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
