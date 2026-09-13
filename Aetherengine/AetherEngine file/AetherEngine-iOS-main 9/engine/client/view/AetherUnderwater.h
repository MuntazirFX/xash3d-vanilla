#ifndef AETHER_AETHERUNDERWATER_H
#define AETHER_AETHERUNDERWATER_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherunderwater_state { bool enabled; f32 value; u32 events; char text[128]; } aetherunderwater_state_t;
void aetherunderwater_init(aetherunderwater_state_t *s);
void aetherunderwater_update(aetherunderwater_state_t *s, f32 dt);
void aetherunderwater_reset(aetherunderwater_state_t *s);
void aetherunderwater_event(aetherunderwater_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
