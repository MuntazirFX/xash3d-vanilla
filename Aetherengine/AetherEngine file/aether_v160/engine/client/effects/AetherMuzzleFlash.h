#ifndef AETHER_AETHERMUZZLEFLASH_H
#define AETHER_AETHERMUZZLEFLASH_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethermuzzleflash_state { bool enabled; f32 value; u32 events; char text[128]; } aethermuzzleflash_state_t;
void aethermuzzleflash_init(aethermuzzleflash_state_t *s);
void aethermuzzleflash_update(aethermuzzleflash_state_t *s, f32 dt);
void aethermuzzleflash_reset(aethermuzzleflash_state_t *s);
void aethermuzzleflash_event(aethermuzzleflash_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
