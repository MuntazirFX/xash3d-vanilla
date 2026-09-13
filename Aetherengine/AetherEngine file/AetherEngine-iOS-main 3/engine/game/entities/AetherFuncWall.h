#ifndef AETHER_AETHERFUNCWALL_H
#define AETHER_AETHERFUNCWALL_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherfuncwall_state { bool enabled; f32 value; u32 events; char text[128]; } aetherfuncwall_state_t;
void aetherfuncwall_init(aetherfuncwall_state_t *s);
void aetherfuncwall_update(aetherfuncwall_state_t *s, f32 dt);
void aetherfuncwall_reset(aetherfuncwall_state_t *s);
void aetherfuncwall_event(aetherfuncwall_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
