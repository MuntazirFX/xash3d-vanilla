#ifndef AETHER_PVS_H
#define AETHER_PVS_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aether_pvs { u32 leaf_count; u32 row_bytes; u8 *bits; } aether_pvs_t;
aether_result_t aether_pvs_init(aether_pvs_t*p,u32 leaves);
void aether_pvs_free(aether_pvs_t*p);
void aether_pvs_set_visible(aether_pvs_t*p,u32 from,u32 to,bool visible);
bool aether_pvs_visible(const aether_pvs_t*p,u32 from,u32 to);
#ifdef __cplusplus
}
#endif
#endif
