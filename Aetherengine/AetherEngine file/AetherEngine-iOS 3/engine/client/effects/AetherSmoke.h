#ifndef AETHER_AETHERSMOKE_H
#define AETHER_AETHERSMOKE_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethersmoke_state { bool enabled; f32 value; u32 events; char text[128]; } aethersmoke_state_t;
void aethersmoke_init(aethersmoke_state_t *s);
void aethersmoke_update(aethersmoke_state_t *s, f32 dt);
void aethersmoke_reset(aethersmoke_state_t *s);
void aethersmoke_event(aethersmoke_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
