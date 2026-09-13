#include "AetherMDLSequence.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MDL_HEADER_SIZE 244u
#define MDL_SEQDESC_SIZE 176u
#define HDR_NUMSEQ 164u
#define HDR_SEQIDX 168u

static i32 rd_i32(const u8 *p) {
    return (i32)((u32)p[0] | ((u32)p[1] << 8) | ((u32)p[2] << 16) | ((u32)p[3] << 24));
}
static f32 rd_f32(const u8 *p) {
    u32 v = (u32)p[0] | ((u32)p[1] << 8) | ((u32)p[2] << 16) | ((u32)p[3] << 24);
    f32 f; memcpy(&f, &v, sizeof f); return f;
}
static void rd_name(const u8 *p, char *out, size_t cap) {
    if (!out || cap == 0) return;
    size_t i = 0;
    for (; i + 1 < cap; ++i) { out[i] = (char)p[i]; if (out[i] == '\0') break; }
    out[cap - 1] = '\0';
}

/* studioseqdesc_t layout used here is represented by byte offsets so the
   parser never depends on compiler packing/alignment. */
aether_result_t aether_mdl_sequences_parse(const aether_mdl_t *mdl,
                                           aether_mdl_sequence_set_t *out) {
    if (!out) return AETHER_ERR_INVALID_ARG;
    memset(out, 0, sizeof *out);
    if (!mdl || !aether_mdl_is_valid(mdl)) return AETHER_ERR_INVALID_ARG;

    u32 raw_size = 0;
    const u8 *raw = aether_mdl_raw_data(mdl, &raw_size);
    if (!raw || raw_size < MDL_HEADER_SIZE) return AETHER_ERR_INVALID_ARG;

    i32 count = rd_i32(raw + HDR_NUMSEQ);
    i32 offset = rd_i32(raw + HDR_SEQIDX);
    if (count <= 0 || offset <= 0) return AETHER_ERR_NOT_FOUND;
    if ((u64)offset + (u64)count * MDL_SEQDESC_SIZE > raw_size) return AETHER_ERR_GENERIC;

    aether_mdl_sequence_t *items = (aether_mdl_sequence_t *)calloc((size_t)count, sizeof *items);
    if (!items) return AETHER_ERR_OUT_OF_MEM;

    for (i32 i = 0; i < count; ++i) {
        const u8 *p = raw + (u32)offset + (u32)i * MDL_SEQDESC_SIZE;
        rd_name(p + 0, items[i].label, sizeof items[i].label);
        items[i].fps = rd_f32(p + 32);
        items[i].flags = rd_i32(p + 40);
        items[i].activity = rd_i32(p + 44);
        items[i].activity_weight = rd_i32(p + 48);
        items[i].num_events = rd_i32(p + 52);
        items[i].event_index = rd_i32(p + 56);
        items[i].num_frames = rd_i32(p + 60);
        items[i].num_blends = rd_i32(p + 80);
        items[i].motion_type = rd_i32(p + 84);
        items[i].motion_bone = rd_i32(p + 88);
        for (int k = 0; k < 3; ++k) items[i].linearmovement[k] = rd_f32(p + 92 + k * 4);
        for (int k = 0; k < 3; ++k) items[i].bbmin[k] = rd_f32(p + 104 + k * 4);
        for (int k = 0; k < 3; ++k) items[i].bbmax[k] = rd_f32(p + 116 + k * 4);
        items[i].blend_type[0] = rd_i32(p + 128);
        items[i].blend_type[1] = rd_i32(p + 132);
        items[i].blend_start[0] = rd_f32(p + 136);
        items[i].blend_start[1] = rd_f32(p + 140);
        items[i].blend_end[0] = rd_f32(p + 144);
        items[i].blend_end[1] = rd_f32(p + 148);
        items[i].blend_parent = rd_i32(p + 152);

        if (items[i].fps < 0.0f) items[i].fps = 0.0f;
        if (items[i].num_frames < 1) items[i].num_frames = 1;
        if (items[i].num_blends < 1) items[i].num_blends = 1;
    }

    out->items = items;
    out->count = (u32)count;
    return AETHER_OK;
}

void aether_mdl_sequences_free(aether_mdl_sequence_set_t *set) {
    if (!set) return;
    free(set->items);
    memset(set, 0, sizeof *set);
}

const aether_mdl_sequence_t *aether_mdl_sequence_at(const aether_mdl_sequence_set_t *set, u32 index) {
    if (!set || !set->items || index >= set->count) return NULL;
    return &set->items[index];
}

const aether_mdl_sequence_t *aether_mdl_sequence_find(const aether_mdl_sequence_set_t *set,
                                                       const char *label) {
    if (!set || !label) return NULL;
    for (u32 i = 0; i < set->count; ++i)
        if (strcmp(set->items[i].label, label) == 0) return &set->items[i];
    return NULL;
}

void aether_mdl_sequences_dump(const aether_mdl_sequence_set_t *set) {
    if (!set) return;
    aether_log(AETHER_LOG_INFO, "mdl-seq", "sequences: %u", set->count);
    u32 shown = set->count > 12u ? 12u : set->count;
    for (u32 i = 0; i < shown; ++i) {
        const aether_mdl_sequence_t *s = &set->items[i];
        aether_log(AETHER_LOG_INFO, "mdl-seq", "  [%u] %-24s frames=%d fps=%.2f blends=%d",
                   i, s->label, s->num_frames, s->fps, s->num_blends);
    }
    if (set->count > shown)
        aether_log(AETHER_LOG_INFO, "mdl-seq", "  ... +%u more", set->count - shown);
}
