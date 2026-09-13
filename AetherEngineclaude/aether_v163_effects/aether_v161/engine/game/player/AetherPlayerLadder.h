#ifndef AETHER_AETHERPLAYERLADDER_H
#define AETHER_AETHERPLAYERLADDER_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherplayerladder_state { bool enabled; f32 value; u32 events; char text[128]; } aetherplayerladder_state_t;
void aetherplayerladder_init(aetherplayerladder_state_t *s);
void aetherplayerladder_update(aetherplayerladder_state_t *s, f32 dt);
void aetherplayerladder_reset(aetherplayerladder_state_t *s);
void aetherplayerladder_event(aetherplayerladder_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
