#ifndef AETHER_AETHERVOICE_H
#define AETHER_AETHERVOICE_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethervoice_state { bool enabled; f32 value; u32 events; char text[128]; } aethervoice_state_t;
void aethervoice_init(aethervoice_state_t *s);
void aethervoice_update(aethervoice_state_t *s, f32 dt);
void aethervoice_reset(aethervoice_state_t *s);
void aethervoice_event(aethervoice_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
