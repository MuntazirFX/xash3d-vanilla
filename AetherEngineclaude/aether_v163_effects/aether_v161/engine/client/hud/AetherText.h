#ifndef AETHER_TEXT_H
#define AETHER_TEXT_H
#include "../../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
#define AETHER_TEXT_QUEUE_MAX 4
typedef struct {
    char message[128];
    f32  time_left;
} aether_text_entry_t;
typedef struct aethertext_state {
    aether_text_entry_t queue[AETHER_TEXT_QUEUE_MAX];
    u32 count;
} aethertext_state_t;
void aethertext_init(aethertext_state_t *s);
/* Pushes a message; if the queue is full, drops the oldest to make room. */
void aethertext_push(aethertext_state_t *s, const char *message, f32 seconds);
void aethertext_update(aethertext_state_t *s, f32 dt);
#ifdef __cplusplus
}
#endif
#endif
