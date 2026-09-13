#ifndef AETHER_AETHERNETCODE_H
#define AETHER_AETHERNETCODE_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethernetcode_state { bool enabled; f32 value; u32 events; char text[128]; } aethernetcode_state_t;
void aethernetcode_init(aethernetcode_state_t *s);
void aethernetcode_update(aethernetcode_state_t *s, f32 dt);
void aethernetcode_reset(aethernetcode_state_t *s);
void aethernetcode_event(aethernetcode_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
