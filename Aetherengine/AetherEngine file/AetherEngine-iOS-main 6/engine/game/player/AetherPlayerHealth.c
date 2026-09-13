#include "AetherPlayerHealth.h"
#include <string.h>
static f32 clampf_(f32 v,f32 a,f32 b){return v<a?a:v>b?b:v;}
void aether_player_health_init(aether_player_health_t*h){if(!h)return;memset(h,0,sizeof*h);h->max_health=100;h->max_armor=100;h->health=100;h->alive=true;}
void aether_player_health_set(aether_player_health_t*h,f32 hp,f32 ar){if(!h)return;h->health=clampf_(hp,0,h->max_health);h->armor=clampf_(ar,0,h->max_armor);h->alive=h->health>0;}
f32 aether_player_health_apply_damage(aether_player_health_t*h,f32 dmg,f32 ratio){if(!h||dmg<=0||!h->alive)return 0;ratio=clampf_(ratio,0,1);f32 absorbed=clampf_(dmg*ratio,0,h->armor);h->armor-=absorbed;f32 taken=dmg-absorbed;h->health=clampf_(h->health-taken,0,h->max_health);h->alive=h->health>0;return taken;}
void aether_player_health_heal(aether_player_health_t*h,f32 n){if(!h)return;h->health=clampf_(h->health+(n>0?n:0),0,h->max_health);if(h->health>0)h->alive=true;}
void aether_player_health_add_armor(aether_player_health_t*h,f32 n){if(!h)return;h->armor=clampf_(h->armor+(n>0?n:0),0,h->max_armor);}
bool aether_player_health_alive(const aether_player_health_t*h){return h&&h->alive;}
