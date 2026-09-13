#ifndef AETHER_AETHERMULTIMANAGER_H
#define AETHER_AETHERMULTIMANAGER_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethermultimanager_state { bool enabled; f32 value; u32 events; char text[128]; } aethermultimanager_state_t;
void aethermultimanager_init(aethermultimanager_state_t *s);
void aethermultimanager_update(aethermultimanager_state_t *s, f32 dt);
void aethermultimanager_reset(aethermultimanager_state_t *s);
void aethermultimanager_event(aethermultimanager_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
