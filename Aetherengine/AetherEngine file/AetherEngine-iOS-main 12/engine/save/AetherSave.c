#include "AetherSave.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct save_hdr{u32 magic,version;u64 size;}save_hdr_t;
#define SAVE_MAGIC 0x41535431u
aether_result_t aether_save_pack(const void*s,size_t n,aether_save_blob_t*o){if(!s||!o)return AETHER_ERR_INVALID_ARG;save_hdr_t h={SAVE_MAGIC,AETHER_SAVE_VERSION,n};o->size=sizeof h+n;o->data=(u8*)malloc(o->size);if(!o->data)return AETHER_ERR_OUT_OF_MEM;memcpy(o->data,&h,sizeof h);memcpy(o->data+sizeof h,s,n);return AETHER_OK;}
aether_result_t aether_save_unpack(const aether_save_blob_t*b,void*o,size_t cap,size_t*w){if(!b||!o||b->size<sizeof(save_hdr_t))return AETHER_ERR_INVALID_ARG;save_hdr_t h;memcpy(&h,b->data,sizeof h);if(h.magic!=SAVE_MAGIC||h.version!=AETHER_SAVE_VERSION||h.size>b->size-sizeof h)return AETHER_ERR_IO;if(h.size>cap)return AETHER_ERR_OUT_OF_MEM;memcpy(o,b->data+sizeof h,(size_t)h.size);if(w)*w=(size_t)h.size;return AETHER_OK;}
void aether_save_free(aether_save_blob_t*b){if(b){free(b->data);memset(b,0,sizeof*b);}}
aether_result_t aether_save_write_file(const char*p,const void*s,size_t n){aether_save_blob_t b={0};aether_result_t r=aether_save_pack(s,n,&b);if(r!=AETHER_OK)return r;FILE*f=fopen(p,"wb");if(!f){aether_save_free(&b);return AETHER_ERR_IO;}bool ok=fwrite(b.data,1,b.size,f)==b.size;fclose(f);aether_save_free(&b);return ok?AETHER_OK:AETHER_ERR_IO;}
aether_result_t aether_save_read_file(const char*p,void*o,size_t cap,size_t*w){FILE*f=fopen(p,"rb");if(!f)return AETHER_ERR_NOT_FOUND;fseek(f,0,SEEK_END);long n=ftell(f);fseek(f,0,SEEK_SET);if(n<=0){fclose(f);return AETHER_ERR_IO;}aether_save_blob_t b={(u8*)malloc((size_t)n),(size_t)n};if(!b.data){fclose(f);return AETHER_ERR_OUT_OF_MEM;}bool ok=fread(b.data,1,b.size,f)==b.size;fclose(f);aether_result_t r=ok?aether_save_unpack(&b,o,cap,w):AETHER_ERR_IO;aether_save_free(&b);return r;}
