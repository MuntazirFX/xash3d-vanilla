#ifndef AETHER_OBJECTIVES_H
#define AETHER_OBJECTIVES_H
#include "../../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
#define AETHER_OBJECTIVES_MAX 16
typedef struct {
    char text[96];
    bool complete;
} aether_objective_entry_t;
typedef struct aetherobjectives_state {
    aether_objective_entry_t items[AETHER_OBJECTIVES_MAX];
    u32 count;
} aetherobjectives_state_t;
void aetherobjectives_init(aetherobjectives_state_t *s);
/* Returns the index of the new objective, or -1 if the list is full. */
i32  aetherobjectives_add(aetherobjectives_state_t *s, const char *text);
void aetherobjectives_complete(aetherobjectives_state_t *s, i32 index);
u32  aetherobjectives_remaining(const aetherobjectives_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
