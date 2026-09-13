#include "AetherMDLAnimator.h"
#include <string.h>
#include <math.h>

void aether_mdl_animator_init(aether_mdl_animator_t *a) {
    if (!a) return;
    memset(a, 0, sizeof *a);
    a->sequence = -1;
    a->playback_rate = 1.0f;
}

void aether_mdl_animator_bind(aether_mdl_animator_t *a, const aether_mdl_sequence_set_t *set) {
    if (!a) return;
    a->sequences = set;
    a->sequence = -1;
    a->time = 0.0f;
    a->playing = false;
}

bool aether_mdl_animator_play(aether_mdl_animator_t *a, i32 sequence, bool looping, f32 playback_rate) {
    if (!a || !a->sequences || sequence < 0 || (u32)sequence >= a->sequences->count) return false;
    const aether_mdl_sequence_t *s = &a->sequences->items[sequence];
    a->sequence = sequence;
    a->time = 0.0f;
    a->playback_rate = playback_rate > 0.0f ? playback_rate : 1.0f;
    a->looping = looping;
    a->playing = true;
    a->blend[0] = s->blend_start[0];
    a->blend[1] = s->blend_start[1];
    return true;
}

void aether_mdl_animator_stop(aether_mdl_animator_t *a) {
    if (!a) return;
    a->playing = false;
}

void aether_mdl_animator_update(aether_mdl_animator_t *a, f32 dt) {
    if (!a || !a->playing || dt <= 0.0f) return;
    const aether_mdl_sequence_t *s = aether_mdl_animator_current(a);
    if (!s) { a->playing = false; return; }
    const f32 duration = s->fps > 0.0f ? ((f32)((s->num_frames > 1) ? (s->num_frames - 1) : 1) / s->fps) : 0.0f;
    if (duration <= 0.0f) { a->time = 0.0f; a->playing = false; return; }
    a->time += dt * a->playback_rate;
    if (a->time >= duration) {
        if (a->looping) a->time = fmodf(a->time, duration);
        else { a->time = duration; a->playing = false; }
    }
}

const aether_mdl_sequence_t *aether_mdl_animator_current(const aether_mdl_animator_t *a) {
    if (!a || !a->sequences || a->sequence < 0 || (u32)a->sequence >= a->sequences->count) return NULL;
    return &a->sequences->items[a->sequence];
}

f32 aether_mdl_animator_frame(const aether_mdl_animator_t *a) {
    const aether_mdl_sequence_t *s = aether_mdl_animator_current(a);
    if (!a || !s || s->num_frames <= 1) return 0.0f;
    f32 fps = s->fps > 0.0f ? s->fps : 1.0f;
    f32 frame = a->time * fps;
    if (frame > (f32)(s->num_frames - 1)) frame = (f32)(s->num_frames - 1);
    return frame;
}

f32 aether_mdl_animator_normalized(const aether_mdl_animator_t *a) {
    const aether_mdl_sequence_t *s = aether_mdl_animator_current(a);
    if (!a || !s || s->num_frames <= 1) return 0.0f;
    f32 n = aether_mdl_animator_frame(a) / (f32)(s->num_frames - 1);
    return n < 0.0f ? 0.0f : (n > 1.0f ? 1.0f : n);
}

bool aether_mdl_animator_finished(const aether_mdl_animator_t *a) {
    return a ? !a->playing : true;
}
