#ifndef AETHER_AETHERBONECTRL_H
#define AETHER_AETHERBONECTRL_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherbonectrl_state { bool enabled; f32 value; u32 events; char text[128]; } aetherbonectrl_state_t;
void aetherbonectrl_init(aetherbonectrl_state_t *s);
void aetherbonectrl_update(aetherbonectrl_state_t *s, f32 dt);
void aetherbonectrl_reset(aetherbonectrl_state_t *s);
void aetherbonectrl_event(aetherbonectrl_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
