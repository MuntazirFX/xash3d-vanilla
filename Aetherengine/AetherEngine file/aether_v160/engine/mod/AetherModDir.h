#ifndef AETHER_AETHERMODDIR_H
#define AETHER_AETHERMODDIR_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethermoddir_state { bool enabled; f32 value; u32 events; char text[128]; } aethermoddir_state_t;
void aethermoddir_init(aethermoddir_state_t *s);
void aethermoddir_update(aethermoddir_state_t *s, f32 dt);
void aethermoddir_reset(aethermoddir_state_t *s);
void aethermoddir_event(aethermoddir_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
