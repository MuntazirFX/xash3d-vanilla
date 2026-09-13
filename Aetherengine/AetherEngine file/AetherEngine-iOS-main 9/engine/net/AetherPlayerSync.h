#ifndef AETHER_AETHERPLAYERSYNC_H
#define AETHER_AETHERPLAYERSYNC_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherplayersync_state { bool enabled; f32 value; u32 events; char text[128]; } aetherplayersync_state_t;
void aetherplayersync_init(aetherplayersync_state_t *s);
void aetherplayersync_update(aetherplayersync_state_t *s, f32 dt);
void aetherplayersync_reset(aetherplayersync_state_t *s);
void aetherplayersync_event(aetherplayersync_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
