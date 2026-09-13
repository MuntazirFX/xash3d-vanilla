#ifndef AETHER_AETHERWEAPONANIM_H
#define AETHER_AETHERWEAPONANIM_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherweaponanim_state { bool enabled; f32 value; u32 events; char text[128]; } aetherweaponanim_state_t;
void aetherweaponanim_init(aetherweaponanim_state_t *s);
void aetherweaponanim_update(aetherweaponanim_state_t *s, f32 dt);
void aetherweaponanim_reset(aetherweaponanim_state_t *s);
void aetherweaponanim_event(aetherweaponanim_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
