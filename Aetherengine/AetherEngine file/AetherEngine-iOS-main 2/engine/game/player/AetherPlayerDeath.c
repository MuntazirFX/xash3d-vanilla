#include "AetherPlayerDeath.h"
#include <string.h>
void aether_player_death_init(aether_player_death_t*d){if(d)memset(d,0,sizeof*d);if(d)d->respawn_delay=2.0f;}
void aether_player_death_kill(aether_player_death_t*d){if(!d||d->dead)return;d->dead=true;d->timer=0;d->deaths++;}
bool aether_player_death_update(aether_player_death_t*d,f32 dt){if(!d||!d->dead)return false;d->timer+=dt;return d->timer>=d->respawn_delay;}
void aether_player_death_respawn(aether_player_death_t*d,aether_player_health_t*h){if(!d)return;d->dead=false;d->timer=0;if(h)aether_player_health_set(h,h->max_health,0);}
