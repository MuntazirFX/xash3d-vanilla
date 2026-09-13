#ifndef AETHER_AETHERHITBOX_H
#define AETHER_AETHERHITBOX_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherhitbox_state { bool enabled; f32 value; u32 events; char text[128]; } aetherhitbox_state_t;
void aetherhitbox_init(aetherhitbox_state_t *s);
void aetherhitbox_update(aetherhitbox_state_t *s, f32 dt);
void aetherhitbox_reset(aetherhitbox_state_t *s);
void aetherhitbox_event(aetherhitbox_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
