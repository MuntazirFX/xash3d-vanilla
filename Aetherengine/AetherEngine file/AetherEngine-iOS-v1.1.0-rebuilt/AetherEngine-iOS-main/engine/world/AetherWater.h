#ifndef AETHER_AETHERWATER_H
#define AETHER_AETHERWATER_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherwater_state { bool enabled; f32 value; u32 events; char text[128]; } aetherwater_state_t;
void aetherwater_init(aetherwater_state_t *s);
void aetherwater_update(aetherwater_state_t *s, f32 dt);
void aetherwater_reset(aetherwater_state_t *s);
void aetherwater_event(aetherwater_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
