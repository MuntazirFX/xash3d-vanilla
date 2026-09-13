#ifndef AETHER_AETHERCONTROLOPTS_H
#define AETHER_AETHERCONTROLOPTS_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethercontrolopts_state { bool enabled; f32 value; u32 events; char text[128]; } aethercontrolopts_state_t;
void aethercontrolopts_init(aethercontrolopts_state_t *s);
void aethercontrolopts_update(aethercontrolopts_state_t *s, f32 dt);
void aethercontrolopts_reset(aethercontrolopts_state_t *s);
void aethercontrolopts_event(aethercontrolopts_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
