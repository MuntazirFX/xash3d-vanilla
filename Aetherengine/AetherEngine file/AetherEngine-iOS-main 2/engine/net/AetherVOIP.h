#ifndef AETHER_AETHERVOIP_H
#define AETHER_AETHERVOIP_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethervoip_state { bool enabled; f32 value; u32 events; char text[128]; } aethervoip_state_t;
void aethervoip_init(aethervoip_state_t *s);
void aethervoip_update(aethervoip_state_t *s, f32 dt);
void aethervoip_reset(aethervoip_state_t *s);
void aethervoip_event(aethervoip_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
