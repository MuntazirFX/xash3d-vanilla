#ifndef AETHER_AETHEREXPLOSIONFX_H
#define AETHER_AETHEREXPLOSIONFX_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherexplosionfx_state { bool enabled; f32 value; u32 events; char text[128]; } aetherexplosionfx_state_t;
void aetherexplosionfx_init(aetherexplosionfx_state_t *s);
void aetherexplosionfx_update(aetherexplosionfx_state_t *s, f32 dt);
void aetherexplosionfx_reset(aetherexplosionfx_state_t *s);
void aetherexplosionfx_event(aetherexplosionfx_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
