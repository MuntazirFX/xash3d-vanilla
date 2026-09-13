#ifndef AETHER_NETWORK_H
#define AETHER_NETWORK_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aether_net_packet { u8 *data; size_t size,capacity; u32 sequence; } aether_net_packet_t;
typedef struct aether_network { bool connected,server; u32 local_sequence,remote_sequence; f32 latency,loss; } aether_network_t;
void aether_network_init(aether_network_t*n);
void aether_network_disconnect(aether_network_t*n);
aether_result_t aether_network_connect(aether_network_t*n,const char*host,u16 port);
void aether_network_tick(aether_network_t*n,f32 dt);
void aether_net_packet_free(aether_net_packet_t*p);
#ifdef __cplusplus
}
#endif
#endif
