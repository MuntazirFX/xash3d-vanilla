#ifndef AETHER_AETHERINFONODE_H
#define AETHER_AETHERINFONODE_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherinfonode_state { bool enabled; f32 value; u32 events; char text[128]; } aetherinfonode_state_t;
void aetherinfonode_init(aetherinfonode_state_t *s);
void aetherinfonode_update(aetherinfonode_state_t *s, f32 dt);
void aetherinfonode_reset(aetherinfonode_state_t *s);
void aetherinfonode_event(aetherinfonode_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
