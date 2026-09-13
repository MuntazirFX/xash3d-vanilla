#ifndef AETHER_AETHERCHAPTERSELECT_H
#define AETHER_AETHERCHAPTERSELECT_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherchapterselect_state { bool enabled; f32 value; u32 events; char text[128]; } aetherchapterselect_state_t;
void aetherchapterselect_init(aetherchapterselect_state_t *s);
void aetherchapterselect_update(aetherchapterselect_state_t *s, f32 dt);
void aetherchapterselect_reset(aetherchapterselect_state_t *s);
void aetherchapterselect_event(aetherchapterselect_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
