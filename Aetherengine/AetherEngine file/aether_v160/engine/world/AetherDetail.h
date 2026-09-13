#ifndef AETHER_AETHERDETAIL_H
#define AETHER_AETHERDETAIL_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherdetail_state { bool enabled; f32 value; u32 events; char text[128]; } aetherdetail_state_t;
void aetherdetail_init(aetherdetail_state_t *s);
void aetherdetail_update(aetherdetail_state_t *s, f32 dt);
void aetherdetail_reset(aetherdetail_state_t *s);
void aetherdetail_event(aetherdetail_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
