#ifndef RAYLIB_V7_RLIGHTS
#define RAYLIB_V7_RLIGHTS

#include <v7/v7.h>

static inline enum v7_err js_create_light(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_update_light_values(struct v7* v7);

void raylib_v7_load_rlights(struct v7* v7);

#endif