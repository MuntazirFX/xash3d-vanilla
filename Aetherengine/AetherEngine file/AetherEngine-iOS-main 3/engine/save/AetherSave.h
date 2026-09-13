#ifndef AETHER_SAVE_H
#define AETHER_SAVE_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
#define AETHER_SAVE_VERSION 1
typedef struct aether_save_blob { u8 *data; size_t size; } aether_save_blob_t;
aether_result_t aether_save_pack(const void *state,size_t size,aether_save_blob_t*out);
aether_result_t aether_save_unpack(const aether_save_blob_t*blob,void*out,size_t capacity,size_t*written);
void aether_save_free(aether_save_blob_t*b);
aether_result_t aether_save_write_file(const char*path,const void*state,size_t size);
aether_result_t aether_save_read_file(const char*path,void*out,size_t capacity,size_t*written);
#ifdef __cplusplus
}
#endif
#endif
