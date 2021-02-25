#ifndef RAYLIB_V7_RNET
#define RAYLIB_V7_RNET

#include <v7/v7.h>

// TODO: Complete rnet implementation once raysan5 reviews rnet.h
enum v7_err js_init_network_device(struct v7* v7, v7_val_t* res);
enum v7_err js_close_network_device(struct v7* v7, v7_val_t* res);

void raylib_v7_load_rnet(struct v7* v7);

#endif
