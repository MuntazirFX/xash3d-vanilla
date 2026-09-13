#ifndef AETHER_PHYSICS_H
#define AETHER_PHYSICS_H
#include "../core/AetherCore.h"
#include "../core/AetherMath.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aether_aabb { aether_vec3_t min,max; } aether_aabb_t;
typedef struct aether_physics_body { aether_vec3_t position,velocity,acceleration; aether_vec3_t half_extents; f32 mass,friction,restitution; bool dynamic,grounded; } aether_physics_body_t;
void aether_physics_body_init(aether_physics_body_t*b,aether_vec3_t p,aether_vec3_t half_extents,f32 mass);
void aether_physics_integrate(aether_physics_body_t*b,f32 dt,aether_vec3_t gravity);
bool aether_aabb_overlap(aether_aabb_t a,aether_aabb_t b);
void aether_physics_apply_impulse(aether_physics_body_t*b,aether_vec3_t impulse);
#ifdef __cplusplus
}
#endif
#endif
