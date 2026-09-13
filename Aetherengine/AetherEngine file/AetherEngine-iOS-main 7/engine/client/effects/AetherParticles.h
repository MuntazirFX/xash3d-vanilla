#ifndef AETHER_AETHERPARTICLES_H
#define AETHER_AETHERPARTICLES_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherparticles_state { bool enabled; f32 value; u32 events; char text[128]; } aetherparticles_state_t;
void aetherparticles_init(aetherparticles_state_t *s);
void aetherparticles_update(aetherparticles_state_t *s, f32 dt);
void aetherparticles_reset(aetherparticles_state_t *s);
void aetherparticles_event(aetherparticles_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
