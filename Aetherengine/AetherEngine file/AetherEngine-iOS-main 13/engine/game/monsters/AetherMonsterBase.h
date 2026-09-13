#ifndef AETHER_MONSTER_BASE_H
#define AETHER_MONSTER_BASE_H
#include "../../core/AetherCore.h"
#include "../../core/AetherMath.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef enum { AETHER_MONSTER_IDLE=0,AETHER_MONSTER_ALERT,AETHER_MONSTER_COMBAT,AETHER_MONSTER_DEAD } aether_monster_state_t;
typedef struct aether_monster { u32 id; char classname[64]; aether_vec3_t position,velocity; f32 health,max_health,speed,attack_range,attack_cooldown; f32 perception_range; aether_monster_state_t state; bool alive; } aether_monster_t;
void aether_monster_init(aether_monster_t*m,u32 id,const char*classname,aether_vec3_t pos,f32 hp,f32 speed);
void aether_monster_update(aether_monster_t*m,aether_vec3_t target,f32 dt);
f32 aether_monster_damage(aether_monster_t*m,f32 amount);
bool aether_monster_is_alive(const aether_monster_t*m);
#ifdef __cplusplus
}
#endif
#endif
