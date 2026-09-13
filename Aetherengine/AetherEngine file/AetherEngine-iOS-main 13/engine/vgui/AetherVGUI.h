#ifndef AETHER_VGUI_H
#define AETHER_VGUI_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aether_vgui_rect { f32 x,y,w,h; } aether_vgui_rect_t;
typedef struct aether_vgui_widget { u32 id; aether_vgui_rect_t rect; bool visible,enabled,focused; char text[128]; } aether_vgui_widget_t;
typedef struct aether_vgui { aether_vgui_widget_t *widgets; u32 count,capacity; u32 focus; } aether_vgui_t;
void aether_vgui_init(aether_vgui_t*v);
void aether_vgui_free(aether_vgui_t*v);
u32 aether_vgui_add(aether_vgui_t*v,const char*text,aether_vgui_rect_t rect);
void aether_vgui_set_visible(aether_vgui_t*v,u32 id,bool visible);
bool aether_vgui_hit(const aether_vgui_t*v,u32 id,f32 x,f32 y);
void aether_vgui_focus(aether_vgui_t*v,u32 id);
#ifdef __cplusplus
}
#endif
#endif
