#ifndef AETHER_AETHERSAVEMONSTER_H
#define AETHER_AETHERSAVEMONSTER_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethersavemonster_state { bool enabled; f32 value; u32 events; char text[128]; } aethersavemonster_state_t;
void aethersavemonster_init(aethersavemonster_state_t *s);
void aethersavemonster_update(aethersavemonster_state_t *s, f32 dt);
void aethersavemonster_reset(aethersavemonster_state_t *s);
void aethersavemonster_event(aethersavemonster_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
