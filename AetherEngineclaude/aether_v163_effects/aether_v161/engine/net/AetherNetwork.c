#include "AetherNetwork.h"
#include <string.h>
#include <stdlib.h>
void aether_network_init(aether_network_t*n){if(n)memset(n,0,sizeof*n);}
void aether_network_disconnect(aether_network_t*n){if(n)n->connected=false;}
aether_result_t aether_network_connect(aether_network_t*n,const char*host,u16 port){if(!n||!host||!port)return AETHER_ERR_INVALID_ARG;n->connected=true;n->latency=.05f;return AETHER_OK;}
void aether_network_tick(aether_network_t*n,f32 dt){if(n&&n->connected){n->local_sequence++;(void)dt;}}
void aether_net_packet_free(aether_net_packet_t*p){if(p){free(p->data);memset(p,0,sizeof*p);}}
