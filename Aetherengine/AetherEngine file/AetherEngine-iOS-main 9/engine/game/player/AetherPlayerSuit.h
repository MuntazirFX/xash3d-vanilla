#ifndef AETHER_AETHERPLAYERSUIT_H
#define AETHER_AETHERPLAYERSUIT_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherplayersuit_state { bool enabled; f32 value; u32 events; char text[128]; } aetherplayersuit_state_t;
void aetherplayersuit_init(aetherplayersuit_state_t *s);
void aetherplayersuit_update(aetherplayersuit_state_t *s, f32 dt);
void aetherplayersuit_reset(aetherplayersuit_state_t *s);
void aetherplayersuit_event(aetherplayersuit_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
