#ifndef AETHER_AETHERSCHEDULES_H
#define AETHER_AETHERSCHEDULES_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherschedules_state { bool enabled; f32 value; u32 events; char text[128]; } aetherschedules_state_t;
void aetherschedules_init(aetherschedules_state_t *s);
void aetherschedules_update(aetherschedules_state_t *s, f32 dt);
void aetherschedules_reset(aetherschedules_state_t *s);
void aetherschedules_event(aetherschedules_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
