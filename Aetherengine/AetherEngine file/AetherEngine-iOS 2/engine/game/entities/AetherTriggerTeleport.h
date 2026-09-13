#ifndef AETHER_AETHERTRIGGERTELEPORT_H
#define AETHER_AETHERTRIGGERTELEPORT_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aethertriggerteleport_state { bool enabled; f32 value; u32 events; char text[128]; } aethertriggerteleport_state_t;
void aethertriggerteleport_init(aethertriggerteleport_state_t *s);
void aethertriggerteleport_update(aethertriggerteleport_state_t *s, f32 dt);
void aethertriggerteleport_reset(aethertriggerteleport_state_t *s);
void aethertriggerteleport_event(aethertriggerteleport_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
