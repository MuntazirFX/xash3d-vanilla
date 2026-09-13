#ifndef AETHER_AETHERAMBIENT_H
#define AETHER_AETHERAMBIENT_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherambient_state { bool enabled; f32 value; u32 events; char text[128]; } aetherambient_state_t;
void aetherambient_init(aetherambient_state_t *s);
void aetherambient_update(aetherambient_state_t *s, f32 dt);
void aetherambient_reset(aetherambient_state_t *s);
void aetherambient_event(aetherambient_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
