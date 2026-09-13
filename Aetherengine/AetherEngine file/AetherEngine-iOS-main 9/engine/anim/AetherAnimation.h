#ifndef AETHER_ANIMATION_H
#define AETHER_ANIMATION_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aether_animation { i32 sequence; f32 time,rate,duration; bool looping,playing; } aether_animation_t;
void aether_animation_init(aether_animation_t*a);
void aether_animation_play(aether_animation_t*a,i32 sequence,f32 duration,f32 rate,bool loop);
void aether_animation_update(aether_animation_t*a,f32 dt);
bool aether_animation_finished(const aether_animation_t*a);
#ifdef __cplusplus
}
#endif
#endif
