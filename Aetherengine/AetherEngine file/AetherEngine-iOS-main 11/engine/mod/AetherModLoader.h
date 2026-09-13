#ifndef AETHER_AETHERMODLOADER_H
#define AETHER_AETHERMODLOADER_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethermodloader_state { bool enabled; f32 value; u32 events; char text[128]; } aethermodloader_state_t;
void aethermodloader_init(aethermodloader_state_t *s);
void aethermodloader_update(aethermodloader_state_t *s, f32 dt);
void aethermodloader_reset(aethermodloader_state_t *s);
void aethermodloader_event(aethermodloader_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
