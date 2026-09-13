#ifndef AETHER_AETHERSCRIPT_H
#define AETHER_AETHERSCRIPT_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherscript_state { bool enabled; f32 value; u32 events; char text[128]; } aetherscript_state_t;
void aetherscript_init(aetherscript_state_t *s);
void aetherscript_update(aetherscript_state_t *s, f32 dt);
void aetherscript_reset(aetherscript_state_t *s);
void aetherscript_event(aetherscript_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
