#include "AetherAnimation.h"
#include <string.h>
#include <math.h>
void aether_animation_init(aether_animation_t*a){if(a)memset(a,0,sizeof*a),a->rate=1;}
void aether_animation_play(aether_animation_t*a,i32 s,f32 d,f32 r,bool l){if(!a)return;a->sequence=s;a->time=0;a->duration=d>0?d:.001f;a->rate=r>0?r:1;a->looping=l;a->playing=true;}
void aether_animation_update(aether_animation_t*a,f32 dt){if(!a||!a->playing)return;a->time+=dt*a->rate;if(a->time>=a->duration){if(a->looping)a->time=fmodf(a->time,a->duration);else{a->time=a->duration;a->playing=false;}}}
bool aether_animation_finished(const aether_animation_t*a){return a?!a->playing:false;}
