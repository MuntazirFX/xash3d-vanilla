#include "AetherPlayerDamage.h"
#include <math.h>
f32 aether_player_apply_damage(aether_player_health_t*h,const aether_damage_t*d){if(!d)return 0;return aether_player_health_apply_damage(h,d->amount,d->armor_ratio);}
f32 aether_player_fall_damage(f32 speed){if(speed<=580.0f)return 0;f32 x=(speed-580.0f)*0.1f;return x>100?100:x;}
