#ifndef AETHER_MDL_SEQUENCE_H
#define AETHER_MDL_SEQUENCE_H

#include "AetherMDL.h"

#ifdef __cplusplus
extern "C" {
#endif

#define AETHER_MDL_SEQUENCE_LABEL_MAX 32

typedef struct aether_mdl_sequence {
    char label[AETHER_MDL_SEQUENCE_LABEL_MAX];
    f32 fps;
    i32 flags;
    i32 activity;
    i32 activity_weight;
    i32 num_frames;
    i32 num_events;
    i32 event_index;
    i32 num_blends;
    i32 anim_index;
    i32 seq_group;
    i32 motion_type;
    i32 motion_bone;
    f32 linearmovement[3];
    f32 bbmin[3];
    f32 bbmax[3];
    i32 blend_type[2];
    f32 blend_start[2];
    f32 blend_end[2];
    i32 blend_parent;
} aether_mdl_sequence_t;

typedef struct aether_mdl_sequence_set {
    aether_mdl_sequence_t *items;
    u32 count;
} aether_mdl_sequence_set_t;

/* Parse the studio sequence-descriptor table from an already loaded MDL. */
aether_result_t aether_mdl_sequences_parse(const aether_mdl_t *mdl,
                                           aether_mdl_sequence_set_t *out);
void aether_mdl_sequences_free(aether_mdl_sequence_set_t *set);
const aether_mdl_sequence_t *aether_mdl_sequence_at(const aether_mdl_sequence_set_t *set, u32 index);
const aether_mdl_sequence_t *aether_mdl_sequence_find(const aether_mdl_sequence_set_t *set,
                                                       const char *label);
void aether_mdl_sequences_dump(const aether_mdl_sequence_set_t *set);

#ifdef __cplusplus
}
#endif
#endif
