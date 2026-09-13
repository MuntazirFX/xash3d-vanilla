#ifndef AETHER_ARMOR_H
#define AETHER_ARMOR_H
#include "../../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aetherarmor_state {
    i32  display_value;
    bool depleted;       /* armor == 0, icon should gray out */
} aetherarmor_state_t;
void aetherarmor_init(aetherarmor_state_t *s);
void aetherarmor_set(aetherarmor_state_t *s, f32 armor);
#ifdef __cplusplus
}
#endif
#endif
