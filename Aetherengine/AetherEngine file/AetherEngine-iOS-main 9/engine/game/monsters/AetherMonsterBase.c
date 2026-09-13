#include "AetherMonsterBase.h"
#include <string.h>
#include <math.h>
static f32 clamp_(f32 v,f32 a,f32 b){return v<a?a:v>b?b:v;}
void aether_monster_init(aether_monster_t*m,u32 id,const char*n,aether_vec3_t p,f32 hp,f32 speed){if(!m)return;memset(m,0,sizeof*m);m->id=id;m->position=p;m->max_health=hp;m->health=hp;m->speed=speed;m->perception_range=1024;m->attack_range=64;m->state=AETHER_MONSTER_IDLE;m->alive=true;if(n){strncpy(m->classname,n,63);m->classname[63]=0;}}
void aether_monster_update(aether_monster_t*m,aether_vec3_t t,f32 dt){if(!m||!m->alive)return;aether_vec3_t d={t.x-m->position.x,t.y-m->position.y,t.z-m->position.z};f32 dist=sqrtf(d.x*d.x+d.y*d.y+d.z*d.z);m->attack_cooldown=clamp_(m->attack_cooldown-dt,0,99999);if(dist<=m->perception_range){m->state=dist<=m->attack_range?AETHER_MONSTER_COMBAT:AETHER_MONSTER_ALERT;if(dist>m->attack_range&&dist>0.01f){f32 inv=1.0f/dist;m->velocity.x=d.x*inv*m->speed;m->velocity.y=d.y*inv*m->speed;m->velocity.z=0;m->position.x+=m->velocity.x*dt;m->position.y+=m->velocity.y*dt;}}else m->state=AETHER_MONSTER_IDLE;}
f32 aether_monster_damage(aether_monster_t*m,f32 a){if(!m||!m->alive||a<=0)return 0;m->health-=a;if(m->health<=0){m->health=0;m->alive=false;m->state=AETHER_MONSTER_DEAD;}return a;}
bool aether_monster_is_alive(const aether_monster_t*m){return m&&m->alive;}
