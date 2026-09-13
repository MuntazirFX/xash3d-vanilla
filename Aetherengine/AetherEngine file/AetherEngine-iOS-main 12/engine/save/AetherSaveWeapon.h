#ifndef AETHER_AETHERSAVEWEAPON_H
#define AETHER_AETHERSAVEWEAPON_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethersaveweapon_state { bool enabled; f32 value; u32 events; char text[128]; } aethersaveweapon_state_t;
void aethersaveweapon_init(aethersaveweapon_state_t *s);
void aethersaveweapon_update(aethersaveweapon_state_t *s, f32 dt);
void aethersaveweapon_reset(aethersaveweapon_state_t *s);
void aethersaveweapon_event(aethersaveweapon_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
