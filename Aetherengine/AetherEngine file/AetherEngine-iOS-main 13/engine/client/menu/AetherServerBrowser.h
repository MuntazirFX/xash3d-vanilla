#ifndef AETHER_AETHERSERVERBROWSER_H
#define AETHER_AETHERSERVERBROWSER_H
#include "../core/AetherCore.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct aether_menu_server_browser_state { bool enabled; f32 value; u32 events; char text[128]; } aether_menu_server_browser_state_t;
void aether_menu_server_browser_init(aether_menu_server_browser_state_t *s);
void aether_menu_server_browser_update(aether_menu_server_browser_state_t *s, f32 dt);
void aether_menu_server_browser_reset(aether_menu_server_browser_state_t *s);
void aether_menu_server_browser_event(aether_menu_server_browser_state_t *s);
#ifdef __cplusplus
}
#endif
#endif
