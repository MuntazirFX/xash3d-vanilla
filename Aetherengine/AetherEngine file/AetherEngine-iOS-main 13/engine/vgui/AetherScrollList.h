#ifndef AETHER_AETHERSCROLLLIST_H
#define AETHER_AETHERSCROLLLIST_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherscrolllist_state { bool enabled; f32 value; u32 events; char text[128]; } aetherscrolllist_state_t;
void aetherscrolllist_init(aetherscrolllist_state_t *s);
void aetherscrolllist_update(aetherscrolllist_state_t *s, f32 dt);
void aetherscrolllist_reset(aetherscrolllist_state_t *s);
void aetherscrolllist_event(aetherscrolllist_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
