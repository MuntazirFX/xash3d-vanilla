#include "AetherVGUI.h"
#include <stdlib.h>
#include <string.h>
void aether_vgui_init(aether_vgui_t*v){if(v)memset(v,0,sizeof*v);}
void aether_vgui_free(aether_vgui_t*v){if(v){free(v->widgets);memset(v,0,sizeof*v);}}
u32 aether_vgui_add(aether_vgui_t*v,const char*t,aether_vgui_rect_t r){if(!v)return 0;if(v->count==v->capacity){u32 c=v->capacity?v->capacity*2:16;void*n=realloc(v->widgets,c*sizeof*v->widgets);if(!n)return 0;v->widgets=n;v->capacity=c;}aether_vgui_widget_t*w=&v->widgets[v->count];memset(w,0,sizeof*w);w->id=v->count+1;w->rect=r;w->visible=w->enabled=true;if(t){strncpy(w->text,t,127);w->text[127]=0;}return w->id=v->count++ +1;}
void aether_vgui_set_visible(aether_vgui_t*v,u32 id,bool x){if(!v||!id||id>v->count)return;v->widgets[id-1].visible=x;}
bool aether_vgui_hit(const aether_vgui_t*v,u32 id,f32 x,f32 y){if(!v||!id||id>v->count)return false;const aether_vgui_widget_t*w=&v->widgets[id-1];return w->visible&&w->enabled&&x>=w->rect.x&&y>=w->rect.y&&x<=w->rect.x+w->rect.w&&y<=w->rect.y+w->rect.h;}
void aether_vgui_focus(aether_vgui_t*v,u32 id){if(!v)return;for(u32 i=0;i<v->count;i++)v->widgets[i].focused=(v->widgets[i].id==id);v->focus=id;}
