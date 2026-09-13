#ifndef AETHER_AETHERSCRIPTEDSEQ_H
#define AETHER_AETHERSCRIPTEDSEQ_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherscriptedseq_state { bool enabled; f32 value; u32 events; char text[128]; } aetherscriptedseq_state_t;
void aetherscriptedseq_init(aetherscriptedseq_state_t *s);
void aetherscriptedseq_update(aetherscriptedseq_state_t *s, f32 dt);
void aetherscriptedseq_reset(aetherscriptedseq_state_t *s);
void aetherscriptedseq_event(aetherscriptedseq_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
