#ifndef AETHER_AETHERSERVERBROWSER_H
#define AETHER_AETHERSERVERBROWSER_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherserverbrowser_state { bool enabled; f32 value; u32 events; char text[128]; } aetherserverbrowser_state_t;
void aetherserverbrowser_init(aetherserverbrowser_state_t *s);
void aetherserverbrowser_update(aetherserverbrowser_state_t *s, f32 dt);
void aetherserverbrowser_reset(aetherserverbrowser_state_t *s);
void aetherserverbrowser_event(aetherserverbrowser_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
