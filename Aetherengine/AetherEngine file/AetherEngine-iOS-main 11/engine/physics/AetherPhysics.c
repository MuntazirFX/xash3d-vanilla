#include "AetherPhysics.h"
#include <string.h>
static f32 clamp_(f32 v,f32 a,f32 b){return v<a?a:v>b?b:v;}
void aether_physics_body_init(aether_physics_body_t*b,aether_vec3_t p,aether_vec3_t h,f32 m){if(!b)return;memset(b,0,sizeof*b);b->position=p;b->half_extents=h;b->mass=m>0?m:1;b->friction=.8f;b->restitution=.1f;b->dynamic=true;}
bool aether_aabb_overlap(aether_aabb_t a,aether_aabb_t b){return a.min.x<=b.max.x&&a.max.x>=b.min.x&&a.min.y<=b.max.y&&a.max.y>=b.min.y&&a.min.z<=b.max.z&&a.max.z>=b.min.z;}
void aether_physics_apply_impulse(aether_physics_body_t*b,aether_vec3_t i){if(!b||!b->dynamic)return;f32 inv=1.0f/b->mass;b->velocity.x+=i.x*inv;b->velocity.y+=i.y*inv;b->velocity.z+=i.z*inv;}
void aether_physics_integrate(aether_physics_body_t*b,f32 dt,aether_vec3_t g){if(!b||!b->dynamic)return;dt=clamp_(dt,0,.1f);b->velocity.x+=g.x*dt;b->velocity.y+=g.y*dt;b->velocity.z+=g.z*dt;b->position.x+=b->velocity.x*dt;b->position.y+=b->velocity.y*dt;b->position.z+=b->velocity.z*dt;}
