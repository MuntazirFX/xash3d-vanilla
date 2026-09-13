/* AetherFuncDoor.h — func_door: linear sliding door (real implementation).
 * AetherEngine-iOS · Clean-room.
 */
#ifndef AETHER_AETHERFUNCDOOR_H
#define AETHER_AETHERFUNCDOOR_H
#include "../../core/AetherCore.h"
#include "../../core/AetherMath.h"
#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    AETHER_DOOR_CLOSED = 0,
    AETHER_DOOR_OPENING,
    AETHER_DOOR_OPEN,
    AETHER_DOOR_CLOSING
} aether_door_state_t;

typedef struct aetherfuncdoor_state {
    bool   enabled;
    aether_vec3_t pos_closed;
    aether_vec3_t pos_open;
    aether_vec3_t position;     /* current interpolated position */
    f32    speed;               /* units/sec */
    f32    wait;                /* seconds open before auto-close, -1 = stays open */
    f32    wait_timer;
    bool   toggle;              /* true = only opens/closes on trigger, no auto-close */
    bool   locked;
    aether_door_state_t state;
    u32    events;              /* open/close count, for HUD/debug */
    char   targetname[32];
    char   target[32];          /* entity to fire when fully open */
} aetherfuncdoor_state_t;

/* move_dir: unit vector direction the door slides (e.g. {0,0,1} = straight up).
 * distance: how far it travels along move_dir from closed position. */
void aetherfuncdoor_init(aetherfuncdoor_state_t *s, aether_vec3_t origin,
                          aether_vec3_t move_dir, f32 distance,
                          f32 speed, f32 wait, bool toggle);
void aetherfuncdoor_update(aetherfuncdoor_state_t *s, f32 dt);
void aetherfuncdoor_reset(aetherfuncdoor_state_t *s);

/* Called when a player/trigger activates the door. */
void aetherfuncdoor_use(aetherfuncdoor_state_t *s);

bool aetherfuncdoor_is_open(const aetherfuncdoor_state_t *s);
bool aetherfuncdoor_is_moving(const aetherfuncdoor_state_t *s);
/* Blocks a door mid-travel (e.g. player standing in doorway) — pushes it back to reverse state. */
void aetherfuncdoor_block(aetherfuncdoor_state_t *s);

#ifdef __cplusplus
}
#endif
#endif
