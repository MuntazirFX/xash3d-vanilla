#ifndef AETHER_AETHERITEM_H
#define AETHER_AETHERITEM_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetheritem_state { bool enabled; f32 value; u32 events; char text[128]; } aetheritem_state_t;
void aetheritem_init(aetheritem_state_t *s);
void aetheritem_update(aetheritem_state_t *s, f32 dt);
void aetheritem_reset(aetheritem_state_t *s);
void aetheritem_event(aetheritem_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
