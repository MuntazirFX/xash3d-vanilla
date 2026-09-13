#ifndef AETHER_AETHERPROTOCOL_H
#define AETHER_AETHERPROTOCOL_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherprotocol_state { bool enabled; f32 value; u32 events; char text[128]; } aetherprotocol_state_t;
void aetherprotocol_init(aetherprotocol_state_t *s);
void aetherprotocol_update(aetherprotocol_state_t *s, f32 dt);
void aetherprotocol_reset(aetherprotocol_state_t *s);
void aetherprotocol_event(aetherprotocol_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
