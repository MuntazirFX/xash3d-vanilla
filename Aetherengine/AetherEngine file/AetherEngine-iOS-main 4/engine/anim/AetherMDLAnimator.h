#ifndef AETHER_MDL_ANIMATOR_H
#define AETHER_MDL_ANIMATOR_H

#include "../core/AetherCore.h"
#include "../model/AetherMDLSequence.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct aether_mdl_animator {
    const aether_mdl_sequence_set_t *sequences; /* borrowed */
    i32 sequence;
    f32 time;
    f32 playback_rate;
    f32 blend[2];
    bool playing;
    bool looping;
} aether_mdl_animator_t;

void aether_mdl_animator_init(aether_mdl_animator_t *a);
void aether_mdl_animator_bind(aether_mdl_animator_t *a, const aether_mdl_sequence_set_t *set);
bool aether_mdl_animator_play(aether_mdl_animator_t *a, i32 sequence, bool looping, f32 playback_rate);
void aether_mdl_animator_stop(aether_mdl_animator_t *a);
void aether_mdl_animator_update(aether_mdl_animator_t *a, f32 dt);
const aether_mdl_sequence_t *aether_mdl_animator_current(const aether_mdl_animator_t *a);
f32 aether_mdl_animator_frame(const aether_mdl_animator_t *a);
f32 aether_mdl_animator_normalized(const aether_mdl_animator_t *a);
bool aether_mdl_animator_finished(const aether_mdl_animator_t *a);

#ifdef __cplusplus
}
#endif
#endif
