#ifndef AETHER_AETHERSQUAD_H
#define AETHER_AETHERSQUAD_H
#include "../../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethersquad_state { bool enabled; f32 value; u32 events; char text[128]; } aethersquad_state_t;
void aethersquad_init(aethersquad_state_t *s);
void aethersquad_update(aethersquad_state_t *s, f32 dt);
void aethersquad_reset(aethersquad_state_t *s);
void aethersquad_event(aethersquad_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
