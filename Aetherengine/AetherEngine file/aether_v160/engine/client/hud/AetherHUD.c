#include "AetherHUD.h"
#include <string.h>
static f32 max_(f32 a,f32 b){return a>b?a:b;}
void aether_hud_init(aether_hud_t*h){if(!h)return;memset(h,0,sizeof*h);h->crosshair=true;h->visible=true;}
void aether_hud_set_player(aether_hud_t*h,f32 hp,f32 ar,i32 c,i32 r,u32 w){if(!h)return;h->health=hp;h->armor=ar;h->ammo_clip=c;h->ammo_reserve=r;h->weapon_id=w;}
void aether_hud_damage(aether_hud_t*h,f32 x){if(h)h->damage_flash=max_(h->damage_flash,x);}
void aether_hud_message(aether_hud_t*h,const char*t,f32 s){if(!h)return;strncpy(h->message,t?t:"",127);h->message[127]=0;h->message_timer=s>0?s:0;}
void aether_hud_update(aether_hud_t*h,f32 dt){if(!h)return;h->damage_flash=max_(0,h->damage_flash-dt*2);h->message_timer=max_(0,h->message_timer-dt);}
