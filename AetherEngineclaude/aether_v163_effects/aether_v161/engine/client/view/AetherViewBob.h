#ifndef AETHER_AETHERVIEWBOB_H
#define AETHER_AETHERVIEWBOB_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherviewbob_state { bool enabled; f32 value; u32 events; char text[128]; } aetherviewbob_state_t;
void aetherviewbob_init(aetherviewbob_state_t *s);
void aetherviewbob_update(aetherviewbob_state_t *s, f32 dt);
void aetherviewbob_reset(aetherviewbob_state_t *s);
void aetherviewbob_event(aetherviewbob_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
