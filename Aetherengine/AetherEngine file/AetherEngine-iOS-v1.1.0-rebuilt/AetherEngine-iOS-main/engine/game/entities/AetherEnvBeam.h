#ifndef AETHER_AETHERENVBEAM_H
#define AETHER_AETHERENVBEAM_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherenvbeam_state { bool enabled; f32 value; u32 events; char text[128]; } aetherenvbeam_state_t;
void aetherenvbeam_init(aetherenvbeam_state_t *s);
void aetherenvbeam_update(aetherenvbeam_state_t *s, f32 dt);
void aetherenvbeam_reset(aetherenvbeam_state_t *s);
void aetherenvbeam_event(aetherenvbeam_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
