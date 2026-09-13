#include "AetherPlayerInventory.h"
#include <string.h>
static i32 ammo_idx(const aether_player_inventory_t*i,const char*n){if(!i||!n)return -1;for(u32 k=0;k<i->ammo_count;k++)if(strcmp(i->ammo[k].name,n)==0)return(i32)k;return -1;}
void aether_player_inventory_init(aether_player_inventory_t*i){if(i)memset(i,0,sizeof*i),i->current_weapon=-1;}
bool aether_player_inventory_add_weapon(aether_player_inventory_t*i,u32 id){if(!i||!id||aether_player_inventory_has_weapon(i,id)||i->weapon_count>=AETHER_MAX_WEAPONS)return false;i->weapon_ids[i->weapon_count++]=id;if(i->current_weapon<0)i->current_weapon=0;return true;}
bool aether_player_inventory_has_weapon(const aether_player_inventory_t*i,u32 id){if(!i)return false;for(u32 k=0;k<i->weapon_count;k++)if(i->weapon_ids[k]==id)return true;return false;}
void aether_player_inventory_set_current(aether_player_inventory_t*i,i32 idx){if(i&&idx>=0&&(u32)idx<i->weapon_count)i->current_weapon=idx;}
i32 aether_player_inventory_current(const aether_player_inventory_t*i){return i?i->current_weapon:-1;}
bool aether_player_inventory_add_ammo(aether_player_inventory_t*i,const char*n,i32 nadd,i32 max){if(!i||!n||nadd<0)return false;i32 k=ammo_idx(i,n);if(k<0){if(i->ammo_count>=AETHER_MAX_AMMO)return false;k=(i32)i->ammo_count++;strncpy(i->ammo[k].name,n,31);i->ammo[k].name[31]=0;i->ammo[k].max_count=max>0?max:999;}i->ammo[k].count=i->ammo[k].count+nadd>i->ammo[k].max_count?i->ammo[k].max_count:i->ammo[k].count+nadd;return true;}
i32 aether_player_inventory_ammo(const aether_player_inventory_t*i,const char*n){i32 k=ammo_idx(i,n);return k<0?0:i->ammo[k].count;}
bool aether_player_inventory_use_ammo(aether_player_inventory_t*i,const char*name,i32 amount){i32 k=ammo_idx(i,name);if(k<0||amount<=0||i->ammo[k].count<amount)return false;i->ammo[k].count-=amount;return true;}
