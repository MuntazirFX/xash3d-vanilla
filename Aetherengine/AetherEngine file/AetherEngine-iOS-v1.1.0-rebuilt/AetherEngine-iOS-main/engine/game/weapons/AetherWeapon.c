#include "AetherWeapon.h"
#include <string.h>
static f32 maxf_(f32 a,f32 b){return a>b?a:b;}
void aether_weapon_init(aether_weapon_t*w,aether_weapon_id_t id,const char*n,i32 cm,f32 dmg,f32 delay,f32 range,bool aut){if(!w)return;memset(w,0,sizeof*w);w->id=id;w->clip_max=cm;w->clip=cm;w->damage=dmg;w->fire_delay=delay;w->range=range;w->automatic=aut;if(n){strncpy(w->classname,n,31);w->classname[31]=0;}}
void aether_weapon_tick(aether_weapon_t*w,f32 dt){if(w)w->cooldown=maxf_(0,w->cooldown-dt);}
bool aether_weapon_can_fire(const aether_weapon_t*w){return w&&w->cooldown<=0&&w->clip>0;}
bool aether_weapon_fire(aether_weapon_t*w){if(!aether_weapon_can_fire(w))return false;w->clip--;w->cooldown=w->fire_delay;w->attacking=true;return true;}
bool aether_weapon_reload(aether_weapon_t*w){if(!w||w->clip>=w->clip_max||w->ammo<=0)return false;i32 n=w->clip_max-w->clip;if(n>w->ammo)n=w->ammo;w->clip+=n;w->ammo-=n;return true;}
