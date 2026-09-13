#ifndef AETHER_AETHERRAGDOLLANIM_H
#define AETHER_AETHERRAGDOLLANIM_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherragdollanim_state { bool enabled; f32 value; u32 events; char text[128]; } aetherragdollanim_state_t;
void aetherragdollanim_init(aetherragdollanim_state_t *s);
void aetherragdollanim_update(aetherragdollanim_state_t *s, f32 dt);
void aetherragdollanim_reset(aetherragdollanim_state_t *s);
void aetherragdollanim_event(aetherragdollanim_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
