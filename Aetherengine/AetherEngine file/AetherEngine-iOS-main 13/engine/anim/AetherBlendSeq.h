#ifndef AETHER_AETHERBLENDSEQ_H
#define AETHER_AETHERBLENDSEQ_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherblendseq_state { bool enabled; f32 value; u32 events; char text[128]; } aetherblendseq_state_t;
void aetherblendseq_init(aetherblendseq_state_t *s);
void aetherblendseq_update(aetherblendseq_state_t *s, f32 dt);
void aetherblendseq_reset(aetherblendseq_state_t *s);
void aetherblendseq_event(aetherblendseq_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
