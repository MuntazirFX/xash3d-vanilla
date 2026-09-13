#include "AetherEntityBase.h"
#include <string.h>
void aether_entity_base_init(aether_entity_base_t*e,u64 uid,const char*n,aether_vec3_t o){if(!e)return;memset(e,0,sizeof*e);e->uid=uid;e->origin=o;e->enabled=true;e->solid=true;e->touchable=true;e->health=100;if(n){strncpy(e->classname,n,63);e->classname[63]=0;}}
void aether_entity_base_set_enabled(aether_entity_base_t*e,bool v){if(e)e->enabled=v;}
void aether_entity_base_tick(aether_entity_base_t*e,f32 dt){if(!e||!e->enabled)return;e->origin.x+=e->velocity.x*dt;e->origin.y+=e->velocity.y*dt;e->origin.z+=e->velocity.z*dt;}
bool aether_entity_base_damage(aether_entity_base_t*e,f32 a){if(!e||!e->enabled||a<=0)return false;e->health-=a;if(e->health<=0){e->health=0;e->enabled=false;return true;}return false;}
