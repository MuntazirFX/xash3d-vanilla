#ifndef AETHER_ENTITY_BASE_H
#define AETHER_ENTITY_BASE_H
#include "../../core/AetherCore.h"
#include "../../core/AetherMath.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aether_entity_base { u64 uid; char classname[64]; aether_vec3_t origin,angles,velocity; f32 health; bool enabled,solid,touchable; void *user; } aether_entity_base_t;
void aether_entity_base_init(aether_entity_base_t*e,u64 uid,const char*classname,aether_vec3_t origin);
void aether_entity_base_set_enabled(aether_entity_base_t*e,bool enabled);
void aether_entity_base_tick(aether_entity_base_t*e,f32 dt);
bool aether_entity_base_damage(aether_entity_base_t*e,f32 amount);
#ifdef __cplusplus
}
#endif
#endif
