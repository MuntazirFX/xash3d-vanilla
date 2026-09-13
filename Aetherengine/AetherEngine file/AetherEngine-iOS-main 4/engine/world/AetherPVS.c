#include "AetherPVS.h"
#include <stdlib.h>
#include <string.h>
aether_result_t aether_pvs_init(aether_pvs_t*p,u32 n){if(!p||!n)return AETHER_ERR_INVALID_ARG;memset(p,0,sizeof*p);p->leaf_count=n;p->row_bytes=(n+7)/8;p->bits=(u8*)calloc((size_t)n,p->row_bytes);return p->bits?AETHER_OK:AETHER_ERR_OUT_OF_MEM;}
void aether_pvs_free(aether_pvs_t*p){if(p){free(p->bits);memset(p,0,sizeof*p);}}
void aether_pvs_set_visible(aether_pvs_t*p,u32 a,u32 b,bool v){if(!p||a>=p->leaf_count||b>=p->leaf_count)return;u8*bit=&p->bits[(size_t)a*p->row_bytes+(b>>3)];u8 mask=(u8)(1u<<(b&7));if(v)*bit|=mask;else *bit&=(u8)~mask;}
bool aether_pvs_visible(const aether_pvs_t*p,u32 a,u32 b){if(!p||a>=p->leaf_count||b>=p->leaf_count)return false;return (p->bits[(size_t)a*p->row_bytes+(b>>3)]&(1u<<(b&7)))!=0;}
