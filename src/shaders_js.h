#ifndef RAYLIB_V7_SHADERS
#define RAYLIB_V7_SHADERS

#include <v7/v7.h>

static inline enum v7_err js_load_shader(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_load_shader_code(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_unload_shader(struct v7* v7);

static inline enum v7_err js_get_shader_default(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_texture_default(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_shapes_texture(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_shapes_texture_rec(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_set_shapes_texture(struct v7* v7);

static inline enum v7_err js_get_shader_location(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_shader_location_attrib(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_set_shader_value(struct v7* v7);
static inline enum v7_err js_set_shader_value_v(struct v7* v7);
static inline enum v7_err js_set_shader_value_matrix(struct v7* v7);
static inline enum v7_err js_set_shader_value_texture(struct v7* v7);
static inline enum v7_err js_set_matrix_projection(struct v7* v7);
static inline enum v7_err js_set_matrix_modelview(struct v7* v7);
static inline enum v7_err js_get_matrix_modelview(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_matrix_projection(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_gen_texture_cubemap(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gen_texture_irriadiance(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gen_texture_prefilter(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gen_texture_brdf(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_begin_shader_mode(struct v7* v7);
static inline enum v7_err js_end_shader_mode(void);
static inline enum v7_err js_begin_blend_mode(struct v7* v7);
static inline enum v7_err js_end_blend_mode(void);

static inline enum v7_err js_init_vr_simulator(void);
static inline enum v7_err js_close_vr_simulator(void);
static inline enum v7_err js_update_vr_tracking(struct v7* v7);
static inline enum v7_err js_set_vr_configuration(struct v7* v7);
static inline enum v7_err js_vr_simulator_ready(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_toggle_vr_mode(void);
static inline enum v7_err js_begin_vr_drawing(void);
static inline enum v7_err js_end_vr_drawing(void);

void raylib_v7_load_shaders(struct v7* v7);

#endif