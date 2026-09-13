#ifndef AETHER_AETHERCUSTOMASSETS_H
#define AETHER_AETHERCUSTOMASSETS_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethercustomassets_state { bool enabled; f32 value; u32 events; char text[128]; } aethercustomassets_state_t;
void aethercustomassets_init(aethercustomassets_state_t *s);
void aethercustomassets_update(aethercustomassets_state_t *s, f32 dt);
void aethercustomassets_reset(aethercustomassets_state_t *s);
void aethercustomassets_event(aethercustomassets_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
