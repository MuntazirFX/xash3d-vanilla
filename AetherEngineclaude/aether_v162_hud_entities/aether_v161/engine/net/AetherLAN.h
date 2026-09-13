#ifndef AETHER_AETHERLAN_H
#define AETHER_AETHERLAN_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherlan_state { bool enabled; f32 value; u32 events; char text[128]; } aetherlan_state_t;
void aetherlan_init(aetherlan_state_t *s);
void aetherlan_update(aetherlan_state_t *s, f32 dt);
void aetherlan_reset(aetherlan_state_t *s);
void aetherlan_event(aetherlan_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
