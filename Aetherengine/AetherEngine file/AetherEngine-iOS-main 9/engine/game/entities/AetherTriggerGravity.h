#ifndef AETHER_AETHERTRIGGERGRAVITY_H
#define AETHER_AETHERTRIGGERGRAVITY_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethertriggergravity_state { bool enabled; f32 value; u32 events; char text[128]; } aethertriggergravity_state_t;
void aethertriggergravity_init(aethertriggergravity_state_t *s);
void aethertriggergravity_update(aethertriggergravity_state_t *s, f32 dt);
void aethertriggergravity_reset(aethertriggergravity_state_t *s);
void aethertriggergravity_event(aethertriggergravity_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
