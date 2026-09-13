#ifndef AETHER_AETHERGIBS_H
#define AETHER_AETHERGIBS_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethergibs_state { bool enabled; f32 value; u32 events; char text[128]; } aethergibs_state_t;
void aethergibs_init(aethergibs_state_t *s);
void aethergibs_update(aethergibs_state_t *s, f32 dt);
void aethergibs_reset(aethergibs_state_t *s);
void aethergibs_event(aethergibs_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
