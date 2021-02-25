// NOTE: I'm gonna complete rnet implementation once raysan5 reviews rnet.h completely...
#define RNET_IMPLEMENTATION

#include <rnet.h>
#include <v7/v7.h>
#include <rnet_js.h>

enum v7_err js_init_network_device(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_boolean(v7, (int)InitNetworkDevice());
    return V7_OK;
}

enum v7_err js_close_network_device(struct v7* v7, v7_val_t* res) {
    CloseNetworkDevice();
    return V7_OK;
}

void raylib_v7_load_rnet(struct v7* v7) {
    v7_set_method(v7, v7_get_global(v7), "InitNetworkDevice", &js_init_network_device);
    v7_set_method(v7, v7_get_global(v7), "CloseNetworkDevice", &js_close_network_device);
}
