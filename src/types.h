#ifndef RAYLIB_V7_TYPES
#define RAYLIB_V7_TYPES

#include <v7/v7.h>

static inline enum v7_err js_color(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_vec2(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_vec3(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_vec4(struct v7* v7, v7_val_t* res); // NOTE: Quaternion type also uses js_vec4
static inline enum v7_err js_rect(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_matrix(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_ray(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_bounding_box(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_npatch_info(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_transform(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_camera_3d(struct v7* v7, v7_val_t* res); // NOTE: Camera type also uses js_camera_3d
static inline enum v7_err js_camera_2d(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_vr_device_info(struct v7* v7, v7_val_t* res);

void raylib_v7_load_types(struct v7* v7);

#endif
